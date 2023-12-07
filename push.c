/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:07:17 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/06 14:05:49 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// contents: pa, pb

// push from b to a
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a && *stack_b)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = tmp;
	}
	write(1, "pa\n", 3);
}

// push from a to b
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a && stack_b)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = tmp;
	}
	write(1, "pb\n", 3);
}
