# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 15:44:24 by mtrembla          #+#    #+#              #
#    Updated: 2022/05/22 17:44:22 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Server Client

SRCS =	client.c \
		server.c \

OBJS = $(SRCS:.c=.o)

LIB = make -C ./LibFT

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

$(NAME):	$(OBJS)
			$(LIB)
			$(CC) $(CFLAGS) $@.o -o $@ LibFT/libft.a

all :	$(NAME)

clean :	
			$(RM) $(OBJS)
			cd ./LibFT && make clean

fclean : clean
				$(RM) $(NAME)
				cd ./LibFT && make fclean

re : fclean all

.PHONY: all clean fclean re