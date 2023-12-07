/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:02 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/06 14:06:16 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_list	*highest(t_list *node)
{
	t_list	*highest;

	highest = node;
	while (node)
	{
		if (node->content > highest->content)
			highest = node;
		if (!node->next)
			break ;
		node = node->next;
	}
	return (highest);
}

t_list	*lowest(t_list *node)
{
	t_list	*lowest;

	lowest = node;
	while (node)
	{
		if (node->content < lowest->content)
			lowest = node;
		if (!node->next)
			break ;
		node = node->next;
	}
	return (lowest);
}

void	mini_sort(t_list **stack)
{
	if (ft_lstsize(*stack) <= 3)
	{
		if (*stack == highest(*stack))
			ra(stack);
		else if ((*stack)->next == highest(*stack))
			rra(stack);
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
	}
}
