# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#    Updated: 2022/04/18 17:13:21 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary

NAME = so_long

# Path

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

WFLAGS = -I./includes/

LIBFT_PATH	= ./libs/libft/libft.a

GNL_PATH = ./libs/gnl/gnl.a


# Name

SRC_NAME =	ini_png.c           \
			parsing.c			\
			error.c				\
			open_file.c			\
			utils.c				\
			trace_img_logic.c	\
			hook_manager.c		\
			patch_mlx.c			\
			check_map.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

MAIN = main.c

# Flags

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror 

FS =# -fsanitize=address -g3

MLX =  -L./libs/mlx/ -lmlx -framework OpenGL -framework AppKit -lz 

# Rules

all: gnl lib mlx $(NAME) 

$(NAME): main.c $(LIBFT) $(OBJ)
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(FS) $(MAIN) $(LIBFT_PATH) $(GNL_PATH) $(OBJ) -o $@ $(MLX)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(WFLAGS) -o $@ -c $<

lib: ./libs/libft/Makefile
	@make -C./libs/libft/

gnl: ./libs/gnl/Makefile
	@make -C ./libs/gnl

mlx: ./libs/mlx/Makefile
	@make -C./libs/mlx/
	@cp ./libs/mlx/libmlx.dylib ./libmlx.dylib

clean:
	@make clean -C ./libs/libft/
	@make clean -C./libs/gnl/
	@make clean -C./libs/mlx/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C ./libs/libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME) ./libmlx.dylib
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette ./includes/*.h
	norminette $(GNL_PATH)*.c 
	norminette $(LIBFT_PATH)*.c


git:
	git add .
	git commit -m "$m"
	git push

.PHONY: all, clean, fclean, re