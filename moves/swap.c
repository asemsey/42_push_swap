/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:47:03 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/08 12:12:12 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// contents: sa, sb, ss

// swap
void	s(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp1 = *stack;
		tmp2 = (*stack)->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*stack = tmp2;
	}
}

// swap a
void	sa(t_list **stack_a)
{
	s(stack_a);
	write(1, "sa\n", 3);
}

// swap b
void	sb(t_list **stack_b)
{
	s(stack_b);
	write(1, "sb\n", 3);
}

// swap both
void	ss(t_list **stack_a, t_list **stack_b)
{
	s(stack_a);
	s(stack_b);
	write(1, "ss\n", 3);
}
