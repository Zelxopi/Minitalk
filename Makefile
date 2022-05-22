# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 15:44:24 by mtrembla          #+#    #+#              #
#    Updated: 2022/05/22 18:03:40 by mtrembla         ###   ########.fr        #
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

clean :	
			$(RM) $(OBJS)
			cd ./libft && make clean

fclean : clean
				$(RM) $(NAME)
				cd ./libft && make fclean

re : fclean all

.PHONY: all clean fclean re
