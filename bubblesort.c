/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:38:15 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/06 14:03:51 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_solve(t_list **stack)
{
	while (*stack != lowest(*stack))
	{
		if (ft_lstsize(lowest(*stack)) > ft_lstsize(*stack) / 2)
			ra(stack);
		else
			rra(stack);
	}
}

void	find_place(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b)->content < highest(*stack_a)->content)
	{
		while ((*stack_b)->content > (*stack_a)->content)
			ra(stack_a);
	}
	else
	{
		while ((*stack_b)->content > (*stack_a)->content && *stack_a != lowest(*stack_a))
			ra(stack_a);
	}
	pa(stack_a, stack_b);
}

void	bubble(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) <= 3)
		mini_sort(stack_a);
	while (*stack_b && ft_lstsize(*stack_b))
	{
		if ((*stack_b)->content < (*stack_a)->content)
			rotate_solve(stack_a);
		find_place(stack_a, stack_b);
	}
	rotate_solve(stack_a);
}
