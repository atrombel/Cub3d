# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/18 13:53:16 by atrombel          #+#    #+#              #
#    Updated: 2026/09/18 13:53:21 by atrombel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

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


ATROMBEL_CFILES =

ATROMBEL_OBJS = $(addprefix $(ATROMBEL_OBJ_DIR)/, $(ATROMBEL_CFILES:.c=.o))
ATROMBEL_NAME = atrombel


CGASSER_CFILES =

CGASSER_OBJS = $(addprefix $(CGASSER_OBJ_DIR)/, $(CGASSER_CFILES:.c=.o))
CGASSER_NAME = cgasser


LIBFT_DIR = libft
LIBFT_INC_DIR = $(LIBFT_DIR)/include
LIBFT = $(LIBFT_DIR)/libft.a

HFILES = cub3D.h atrombel.h cgasser.h

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS) $(ATROMBEL_OBJS) $(CGASSER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(ATROMBEL_OBJS) $(CGASSER_OBJS) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

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

