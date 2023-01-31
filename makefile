# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 19:40:10 by mkarakul          #+#    #+#              #
#    Updated: 2023/01/19 19:40:10 by mkarakul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./

CLIENT = $(CC) $(CFLAGS) client.c minitalk_utils.c -o client

SERVER = $(CC) $(CFLAGS) server.c minitalk_utils.c -o server

BONUS-CLIENT = $(CC) $(CFLAGS) client.c minitalk_utils.c -o client

BONUS_SERVER = $(CC) $(CFLAGS) server.c minitalk_utils.c -o server

CLIENT_NAME = client

SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):
	$(CLIENT)
$(SERVER_NAME):
	$(SERVER)

bonus: $(CLIENT_NAME) $(SERVER_NAME)
	$(BONUS_CLIENT)

clean:
	rm -rf client server
fclean: clean

re: clean all

.PHONY: all clean fclean re