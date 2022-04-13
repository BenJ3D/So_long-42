# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/04/13 19:35:57 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FIXME: Attention relink sur le cp de la dylib

NAME = so_long
LIBSL = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = ./includes/so_long.h
HEADER = ./includes/so_long.h
HEADER_MLX = ./libs/mlx/mlx.h
LIBFTPATH = -C ./libs/libft
LIBFT = ./libs/libft/libft.a
GNL = ./libs/gnl/gnl.a
PATHMLX = ./libs/mlx
FS = -fsanitize=address -g3

PATH_SRCS = ./
FILES_SRCS = ini_png parsing error open_file utils trace_img_logic \
				hook_manager patch_mlx check_map

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_SRCS)))

OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_SRCS)))

all : ${GNL} ${LIBFT} $(NAME)

%.o: %.c $(HEADER) $(SRCS) 
	$(CC) $(CFLAGS) -c -o $@ $(OBJS_DIR)$< 

$(NAME): $(HEADER) ./main.c libmlx  $(OBJS)
	${CC} ${FS} ${CFLAGS} main.c libmlx.dylib -framework OpenGL -framework AppKit -lz \
	$(LIBFT) ${GNL} $(OBJS) -o $(NAME)

libmlx: $(HEADER_MLX)
	make -C $(PATHMLX)
	cp $(PATHMLX)/libmlx.dylib libmlx.dylib

${LIBFT}: 
	make -C ./libs/libft
	make bonus -C ./libs/libft

${GNL}:
	make -C ./libs/gnl

parsing: ${OBJS} ${GNL} ${LIBFT} $(HEADER)
	${CC} ${FS} ${CFLAGS} libmlx.dylib -framework OpenGL -framework AppKit -lz \
	$(LIBFT) ${GNL} $(OBJS)

clean:
	${MAKE} clean $(LIBFTPATH)
	${MAKE} clean -C $(PATHMLX)
	${MAKE} clean -C ./libs/gnl
	rm -rf $(OBJS)

fclean: clean
	${MAKE} fclean $(LIBFTPATH)
	${MAKE} fclean -C ./libs/gnl
	$(RM) $(NAME) libmlx.dylib
	rm -d -rf .vscode so_long*

re: fclean all

git:
	git add .
	git commit -m "$m"
	git push

.PHONY: all clean fclean re