# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 15:44:24 by mtrembla          #+#    #+#              #
#    Updated: 2022/05/22 19:15:15 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Server Client

SRCS =	client.c \
		server.c \

OBJS = $(SRCS:.c=.o)

LIB = make -C ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

$(NAME):	$(OBJS)
			$(LIB)
			$(CC) $(CFLAGS) $@.o -o $@ libft/libft.a

all :	$(NAME)
		@echo "\033[1;32m all\033[0;39m"

clean :	
			$(RM) $(OBJS)
			cd ./libft && make clean

fclean : clean
				$(RM) $(NAME)
				cd ./libft && make fclean
				@echo "\033[1;31m fclean\033[0;39m"

re : fclean all
		@echo "\033[1;35mPotato\033[0;39m"

.PHONY: all clean fclean re
		@echo "\033[1;36mThe 🦆 you doing?\033[0;39m"