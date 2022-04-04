# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/04/04 15:49:10 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBSL = so_long.a
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = ./includes/so_long.h
HEADER = ./includes/so_long.h
HEADER_MLX = ./mlx/mlx.h
LIBFTPATH = -C ./libft
LIBFT = ./libft/libft.a
FS = #-fsanitize=address -g3

all : ${LIBFT} $(NAME)


$(NAME): ./srcs/main.c libmlx $(HEADER)
	${CC} ${FS} ${CFLAGS} srcs/main.c libmlx.dylib -framework OpenGL -framework AppKit -lz \
	-Llibft -lft -o $(NAME)

ifeq ($(UNAME), Linux)
libmlx: $(HEADER_MLX)
	make -C ./mlx
	cp ./mlx/libmlx.dylib libmlx.dylib
endif

ifeq ($(UNAME), Linux)
libmlx: $(HEADER_MLX)
	make -C ./mlx
	cp ./mlx/libmlx.dylib libmlx.dylib
endif
libmlx: $(HEADER_MLX)
	make -C ./mlx
	cp ./mlx/libmlx.dylib libmlx.dylib

${LIBFT}: 
	make -C ./libft
	make bonus -C ./libft

clean:
	${MAKE} clean $(LIBFTPATH)
	${MAKE} clean -C ./mlx

fclean: clean
	make fclean $(LIBFTPATH)
	$(RM) $(NAME) libmlx.dylib
	rm -d -rf .vscode

re: fclean all
#srcs/main.c libmlx.dylib -framework OpenGL -framework AppKit -lz -o $(NAME)
git:
	git add .
	git commit -m "$m"
	git push

.PHONY: all clean fclean re