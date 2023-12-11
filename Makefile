# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 09:07:57 by asemsey           #+#    #+#              #
#    Updated: 2023/12/11 15:03:26 by asemsey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LISTS = lists/ft_lst1.c lists/ft_lst2.c
MOVES = moves/rev_rotate.c moves/rotate.c moves/swap.c moves/push.c
HELPER = helpers/ft_putnbr.c helpers/ft_atoi.c helpers/ft_split.c
SORT = sorting/sort.c sorting/mini_sort.c sorting/set_nodes.c
SRCS = $(LISTS) $(HELPER) $(MOVES) $(SORT) main.c

all: $(NAME)

$(NAME): $(SRCS)
	cc $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all