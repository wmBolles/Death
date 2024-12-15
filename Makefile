# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/15 02:47:49 by root              #+#    #+#              #
#    Updated: 2024/12/15 03:51:59 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -Wall -Wextra -Werror 

NAME	=	daemon
CC		=	gcc
CFLAGS	=	-I./inc
HEADER	=	./inc/daemon.h

FILES	=	./daemon.c \
			./tools/set_data.c \
			./tools/ft_split.c \
			./tools/failedtype.c

OBJCS	=	$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJCS)
	$(CC) $(OBJCS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean