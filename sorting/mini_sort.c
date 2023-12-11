/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:02 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/11 16:01:27 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// checks if stack is in ascending order
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

// sorts 3 or less numbers
void	mini_sort(t_list **stack)
{
	int	len;

	len = ft_lstsize(*stack);
	if (len == 1)
		return ;
	if (len <= 3)
	{
		if (len == 3 && *stack == highest(*stack))
			ra(stack);
		else if (len == 3 && (*stack)->next == highest(*stack))
			rra(stack);
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
	}
}
