# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/03/29 20:47:51 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = ./includes/so_long.h
HEADER_BONUS = ./bonus/includes/minitalk_bonus.h
LIBFTPATH = -C ./libft
LIBFT = ./libft/libft.a
FS = #-fsanitize=address -g3

all : $(NAME) 

${LIBFT}: 
	make -C ./libft
	make bonus -C ./libft

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ) ${LIBFT}
	$(CC) $(OBJ) -framework OpenGL -framework AppKit -lz -o $(NAME)
	
clean:
	${MAKE} clean $(LIBFTPATH)
	$(RM)

fclean: clean
	${MAKE} fclean $(LIBFTPATH)
	$(RM) $(NAME) server client ./bonus/server ./bonus/client
	rm -d -rf server.d* client.d* .vscode

re: fclean all

git:
	git add .
	git commit -m "$m"
	git push

.PHONY: all clean fclean re