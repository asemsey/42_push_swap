/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:24:01 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/11 14:39:17 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// contents: rra, rrb, rrr

// reverse rotate
void	rev_r(t_list **stack)
{
	t_list	*head;
	t_list	*last;
	t_list	*new_last;

	head = *stack;
	if (head && head->next)
	{
		last = ft_lstlast(*stack);
		new_last = *stack;
		while (new_last && new_last->next && new_last->next->next)
			new_last = new_last->next;
		new_last->next = NULL;
		last->next = head;
		*stack = last;
	}
}

// reverse rotate a
void	rra(t_list **stack_a)
{
	rev_r(stack_a);
	set_pos(stack_a);
	write(1, "rra\n", 4);
}

// reverse rotate b
void	rrb(t_list **stack_b)
{
	rev_r(stack_b);
	set_pos(stack_b);
	write(1, "rrb\n", 4);
}

// reverse rotate both
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_r(stack_a);
	rev_r(stack_b);
	set_pos(stack_a);
	set_pos(stack_b);
	write(1, "rrr\n", 4);
}
