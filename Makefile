# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/18 13:53:16 by atrombel          #+#    #+#              #
#    Updated: 2026/10/23 15:16:58 by cgasser          ###   ####lausanne.ch    #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lXext -lX11

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

ATROMBEL_DIR = atrombel
ATROMBEL_SRC_DIR = $(SRC_DIR)/$(ATROMBEL_DIR)
ATROMBEL_OBJ_DIR = $(OBJ_DIR)/$(ATROMBEL_DIR)

CGASSER_DIR = cgasser
CGASSER_SRC_DIR = $(SRC_DIR)/$(CGASSER_DIR)
CGASSER_OBJ_DIR = $(OBJ_DIR)/$(CGASSER_DIR)


CFILES = main.c

SRCS = $(addprefix $(SRC_DIR)/, $(CFILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(CFILES:.c=.o))


ATROMBEL_CFILES = 	parser_main.c \
					parser_argnbr_open_type_check.c\
					print_error.c \
					parser_identifiers_check.c \
					id_storage_path.c \
					world_check_utils.c \
					free_functions.c \
					store_identifier_path.c \
					world_check.c \
					is_next_line_map.c \
					map_storing.c \
					ft_init.c \
					color_storage.c


ATROMBEL_OBJS = $(addprefix $(ATROMBEL_OBJ_DIR)/, $(ATROMBEL_CFILES:.c=.o))
ATROMBEL_NAME = atrombel


CGASSER_CFILES =	ft_game.c \
					ft_game_init.c \
					ft_kill_mlx.c \
					ft_display_init.c \
					ft_draw_map.c \
					ft_map_dim.c \
					ft_is_player.c \




CGASSER_OBJS = $(addprefix $(CGASSER_OBJ_DIR)/, $(CGASSER_CFILES:.c=.o))
CGASSER_NAME = cgasser


LIBFT_DIR = libft
LIBFT_INC_DIR = $(LIBFT_DIR)/
LIBFT = $(LIBFT_DIR)/libft.a

MLX_LIB_DIR = minilibx-linux
MLX_A = $(MLX_LIB_DIR)/libmlx.a
MLX_LINUX_A = $(MLX_LIB_DIR)/libmlx_Linux.a
MLX_A_ALL = $(MLX_A) $(MLX_LINUX_A)

HFILES = cub3D.h atrombel.h cgasser.h

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS) $(ATROMBEL_OBJS) $(CGASSER_OBJS) $(LIBFT) $(MLX_A_ALL)
	$(CC) $(CFLAGS) $(OBJS) $(ATROMBEL_OBJS) $(CGASSER_OBJS) $(LIBFT) $(MLX_A_ALL) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -I $(MLX_LIB_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A_ALL):
	$(MAKE) -C $(MLX_LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

cleanatrombel:
	rm -rf $(ATROMBEL_OBJ_DIR)

fcleanatrombel: cleanatrombel
	rm -rf $(ATROMBEL_NAME)

cleancgasser:
	rm -rf $(CGASSER_OBJ_DIR)

fcleancgasser: cleancgasser
	rm -rf $(CGASSER_NAME)

re: fclean all

.PHONY: all atrombel cgasser debug valgrind clean fclean cleanatrombel fcleanatrombel cleancgasser fcleancgasser re

