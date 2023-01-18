# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 11:32:19 by mkarakul          #+#    #+#              #
#    Updated: 2023/01/18 11:33:22 by mkarakul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./

CLIENT = $(CC) $(CFLAGS) client.c mt_utils.c -o client

SERVER = $(CC) $(CFLAGS) server.c mt_utils.c -o server

all:
	$(CLIENT)
	$(SERVER)
clean:
	rm -rf client server
fclean: clean

re : all

.PHONY: all clean fclean re