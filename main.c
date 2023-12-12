/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:23:56 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/12 14:06:42 by asemsey          ###   ########.fr       */
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
		else if (*str < '0' || '9' < *str)
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
		if (ft_strncmp(ft_itoa(n[i]), nums[i], 100) != 0 && n[i] != 0)
		{
			free_all(nums);
			return (free(n), NULL);
		}
		i++;
	}
	free_all(nums);
	return (n);
}

int	print_error(t_list **lst)
{
	write(2, "Error\n", 6);
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
	if (argc == 1)
		return (1);
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
