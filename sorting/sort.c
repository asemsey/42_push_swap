/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:08:48 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/11 15:01:37 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// returns the node in b that is easiest to move to the correct position in a
t_list	*next_to_move(t_list *b)
{
	t_list	*node;

	node = b;
	while (b)
	{
		if (b->moves + b->target->moves < node->moves + node->target->moves)
			node = b;
		b = b->next;
	}
	return (node);
}

// rotates stack so target is at the top, s is either 'a' or 'b'
void	rotate_to(t_list **stack, t_list *target, char s)
{
	int	len;

	len = ft_lstsize(*stack);
	while (s == 'a' && *stack != target)
	{
		if (target->pos <= len / 2)
			ra(stack);
		else
			rra(stack);
	}
	while (s == 'b' && *stack != target)
	{
		if (target->pos <= len / 2)
			rb(stack);
		else
			rrb(stack);
	}
}

// rotates both stacks and pushes the easiest node to its target in a
void	move_to_a(t_list **a, t_list **b)
{
	t_list	*to_move;
	int		len_a;
	int		len_b;

	to_move = next_to_move(*b);
	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	while (*b != to_move && *a != to_move->target)
	{
		if (to_move->pos > len_b / 2 && to_move->target->pos > len_a)
			rrr(a, b);
		else if (to_move->pos <= len_b / 2 && to_move->target->pos <= len_a)
			rr(a, b);
		else
			break ;
	}
	rotate_to(a, to_move->target, 'a');
	rotate_to(b, to_move, 'b');
	pa(a, b);
}

// main sort function
void	sort(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	while (len > 3)
	{
		pb(a, b);
		len--;
	}
	mini_sort(a);
	while (*b)
	{
		set_nodes(a, b);
		move_to_a(a, b);
	}
	rotate_to(a, lowest(*a), 'a');
}
