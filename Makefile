# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 09:07:57 by asemsey           #+#    #+#              #
#    Updated: 2023/12/06 13:43:50 by asemsey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LISTS = ft_lst.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstprint.c ft_lstsize.c\

SRCS = ft_lst.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstprint.c ft_lstsize.c\
		ft_putnbr.c ft_atoi.c ft_split.c rev_rotate.c rotate.c swap.c push.c mini_sort.c bubblesort.c\
		main.c


all: $(NAME)

copy:
	cp lists/*.c .

$(NAME): copy $(SRCS)
	cc $(CFLAGS) -o $(NAME) $(SRCS)
	rm -f $(LISTS)

clean:
	rm -f $(NAME)
	rm -f $(LISTS)

re: clean all