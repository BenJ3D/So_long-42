# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/04/06 13:05:07 by bducrocq         ###   ########.fr        #
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
HEADER_MLX = ./libs/mlx/mlx.h
LIBFTPATH = -C ./libs/libft
LIBFT = ./libs/libft/libft.a
PATHMLX = ./libs/mlx
FS = #-fsanitize=address -g3

all : ${LIBFT} $(NAME)

$(NAME): ./main.c libmlx $(HEADER)
	${CC} ${FS} ${CFLAGS} main.c libmlx.dylib -framework OpenGL -framework AppKit -lz \
	$(LIBFT) -o $(NAME)

libmlx: $(HEADER_MLX)
	make -C $(PATHMLX)
	cp $(PATHMLX)/libmlx.dylib libmlx.dylib

${LIBFT}: 
	make -C ./libs/libft
	make bonus -C ./libs/libft

clean:
	${MAKE} clean $(LIBFTPATH)
	${MAKE} clean -C $(PATHMLX)

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