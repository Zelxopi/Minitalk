# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 15:44:24 by mtrembla          #+#    #+#              #
#    Updated: 2022/05/25 09:49:55 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

SRCS =	client.c \
		server.c \

SRCS_BONUS = 	client_bonus.c \
				server_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIB = make -C ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

$(NAME):	$(OBJS)
			$(LIB)
			$(CC) $(CFLAGS) $@.o -o $@ libft/libft.a

all :	$(NAME)
		@echo "\033[1;32m all\033[0;39m"

bonus : $(OBJS_BONUS)
		$(LIB)
		$(CC) $(CFLAGS) server_bonus.c libft/libft.a -o server
		$(CC) $(CFLAGS) client_bonus.c libft/libft.a -o client

clean :	
			$(RM) $(OBJS) $(OBJS_BONUS)
			cd ./libft && make clean

fclean : clean
				$(RM) $(NAME) $(OBJS_BONUS)
				cd ./libft && make fclean
				@echo "\033[1;31m fclean\033[0;39m"

re : fclean all
		@echo "\033[1;35mPotato\033[0;39m"

.PHONY: all bonus clean fclean re
		@echo "\033[1;36mThe 🦆 you doing?\033[0;39m"