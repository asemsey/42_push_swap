/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:23:56 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/08 12:11:01 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid(char *str)
{
	while (str && *str)
	{
		while (*str == ' ')
			str++;
		if (*str == '-')
			str++;
		while (*str && *str != ' ')
		{
			if (*str < '0' || '9' < *str)
				return (0);
			str++;
		}
	}
	return (1);
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

int	main(int argc, char **argv)
{
	t_list	**node;
	int		*n;
	int		i;

	i = 1;
	node = malloc(sizeof(t_list *) * 2);
	while (i < argc)
	{
		n = create_stack(argv[i]);
		if (!n)
		{
			write(1, "Error\n", 7);
			return (1);
		}
		ft_lstadd_back(&node[0], ft_lst(n, wordcount(argv[i], ' ')));
		free(n);
		i++;
	}
	if (node && node[0])
		insertion(&node[0], &node[1]);
	return (0);
}
