/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:23:56 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/11 16:47:48 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid(char *str)
{
	if (!str || !*str)
		return (0);
	while (str && *str)
	{
		if (*str == '-')
			str++;
		if (*str < '0' || '9' < *str)
				return (0);
		while (*str && *str != ' ')
		{
			if (*str < '0' || '9' < *str)
				return (0);
			str++;
		}
		if (*str == ' ')
			str++;
	}
	if (*(str - 1) == ' ')
		return (0);
	return (1);
}

int	has_doubles(t_list *lst)
{
	t_list	*num;
	t_list	*head;

	num = lst;
	head = lst;
	while (num)
	{
		lst = head;
		while (lst)
		{
			if (num != lst && num->content == lst->content)
				return (1);
			lst = lst->next;
		}
		num = num->next;
	}
	return (0);
}

int	*create_stack(char *arg)
{
	int		*n;
	char	**nums;
	int		i;

	i = 0;
	if (!valid(arg))
		return (NULL);
	n = (int *)malloc(sizeof(int) * wordcount(arg, ' '));
	nums = ft_split(arg, ' ');
	if (!n || !nums)
		return (NULL);
	while (i < wordcount(arg, ' '))
	{
		n[i] = ft_atoi(nums[i]);
		i++;
	}
	free_all(nums);
	return (n);
}

int	print_error(t_list **lst)
{
	write(1, "Error\n", 7);
	if (*lst)
		free_lst(lst);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*n;
	int		i;

	i = 1;
	b = NULL;
	while (i < argc)
	{
		n = create_stack(argv[i]);
		if (!n)
			return (print_error(&a));
		ft_lstadd_back(&a, ft_lst(n, wordcount(argv[i], ' ')));
		free(n);
		i++;
	}
	if (!a || has_doubles(a))
		return (print_error(&a));
	sort(&a, &b);
	free_lst(&a);
	free_lst(&b);
	return (0);
}


// to check nodes:
// sort(&node[0], &node[1]);
// 	write(1, "list 1:\n", 9);
// 	tmp = node[0];
// 	while (tmp)
// 	{
// 		ft_putnbr(tmp->content);
// 		write(1, "   p: ", 7);
// 		ft_putnbr(tmp->pos);
// 		write(1, "   m: ", 7);
// 		ft_putnbr(tmp->moves);
// 		write(1, "\n", 1);
// 		tmp = tmp->next;
// 	}
// 	write(1, "list 2:\n", 9);
// 	tmp = node[1];
// 	while (tmp)
// 	{
// 		ft_putnbr(tmp->content);
// 		write(1, "   p: ", 7);
// 		ft_putnbr(tmp->pos);
// 		write(1, "   m: ", 7);
// 		ft_putnbr(tmp->moves);
// 		write(1, "   tar: ", 9);
// 		ft_putnbr(tmp->target->content);
// 		write(1, "\n", 1);
// 		tmp = tmp->next;
// 	}