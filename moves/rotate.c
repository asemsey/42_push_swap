/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:19:16 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/11 14:39:42 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// contents: ra, rb, rr

// rotate
void	r(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		head = (*stack)->next;
		last->next = *stack;
		(*stack)->next = NULL;
		*stack = head;
	}
}

// rotate a
void	ra(t_list **stack_a)
{
	r(stack_a);
	set_pos(stack_a);
	write(1, "ra\n", 3);
}

// rotate b
void	rb(t_list **stack_b)
{
	r(stack_b);
	set_pos(stack_b);
	write(1, "rb\n", 3);
}

// rotate both
void	rr(t_list **stack_a, t_list **stack_b)
{
	r(stack_a);
	r(stack_b);
	set_pos(stack_a);
	set_pos(stack_b);
	write(1, "rr\n", 3);
}
