# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/03/15 18:05:03 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = ./includes/minitalk.h
HEADER_BONUS = ./bonus/includes/minitalk_bonus.h
LIBFTPATH = -C ./libft
LIBFT = ./libft/libft.a
FS = #-fsanitize=address -g3

all : ${LIBFT} server client 
	@chmod 700 server client


server : server.c utils.c $(HEADER)
	gcc $(CFLAGS) $(FS) utils.c server.c -Llibft -lft -o server

client : client.c utils.c $(HEADER)
	gcc $(CFLAGS) $(FS) utils.c client.c -Llibft -lft -o client

server_bonus : ./bonus/server_bonus.c utils.c $(HEADER_BONUS)
	gcc $(CFLAGS) $(FS) ./bonus/utils_bonus.c ./bonus/server_bonus.c -Llibft -lft -o ./bonus/server

client_bonus : ./bonus/client_bonus.c utils.c $(HEADER_BONUS)
	gcc $(CFLAGS) $(FS) ./bonus/utils_bonus.c ./bonus/client_bonus.c -Llibft -lft -o ./bonus/client

${LIBFT}: 
	make -C ./libft
	make bonus -C ./libft

bonus: ${LIBFT} $(HEADER_BONUS) server_bonus client_bonus 
	@chmod 700 ./bonus/server ./bonus/client

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