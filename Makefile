# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#    Updated: 2022/04/14 23:01:16 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary

NAME = so_long

# Path

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

CPPFLAGS = -I./includes/

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

LDFLAGS = -L./libs/libft/
GNLFLAGS = -L./libs/gnl/

LFT = -lft
GNLFT = ./libs/gnl/gnl.a

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

MLX =  -L./libs/mlx/ -lmlx -framework OpenGL -framework AppKit -lz 

# Rules

all: $(NAME) 

$(NAME): main.c $(LIBFT) $(OBJ) 
	@make -C./libs/libft/
	@make -C./libs/gnl/
	@make -C./libs/mlx/
	@cp ./libs/mlx/libmlx.dylib ./libmlx.dylib
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(MAIN) $(LDFLAGS) $(LFT) $(GNLFLAGS) $(GNLFT) $(OBJ) -o $@ $(MLX)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

$(LIBFT):
	@make -C./libs/libft/

${GNL}:
	@make -C ./libs/gnl

clean:
	@make clean -C ./libs/libft/
	@make clean -C./libs/gnl/
	@make clean -C./libs/mlx/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C ./libs/libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME) ./libmlx.dylib
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

git:
	git add .
	git commit -m "$m"
	git push

.PHONY: all, clean, fclean, re