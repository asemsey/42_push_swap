/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:47:47 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/11 17:51:33 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// gives b_node its target (greater but smallest difference)
void	get_target(t_list **a, t_list **b_node)
{
	t_list	*head;

	head = *a;
	(*b_node)->target = NULL;
	while (*a && !(*b_node)->target)
	{
		if ((*a)->content > (*b_node)->content)
			(*b_node)->target = *a;
		*a = (*a)->next;
	}
	while (*a && (*b_node)->target)
	{
		if ((*a)->content > (*b_node)->content
			&& (*a)->content - (*b_node)->content
			< (*b_node)->target->content - (*b_node)->content)
			(*b_node)->target = *a;
		*a = (*a)->next;
	}
	if (!(*b_node)->target)
		(*b_node)->target = lowest(head);
	*a = head;
}

// sets all targets
void	set_target(t_list **a, t_list **b)
{
	t_list	*head;

	head = *b;
	while (*b)
	{
		get_target(a, b);
		*b = (*b)->next;
	}
	*b = head;
}

// sets the position of all nodes in the stack (0 to len-1)
void	set_pos(t_list **stack)
{
	t_list	*head;
	int		p;

	head = *stack;
	p = 0;
	while (*stack)
	{
		(*stack)->pos = p++;
		*stack = (*stack)->next;
	}
	*stack = head;
}

// sets the amount of moves it takes to move each node to the top of its stack
void	set_moves(t_list **a, t_list **b)
{
	t_list	*head;
	int		len;

	head = *a;
	len = ft_lstsize(*a);
	while (*a)
	{
		if ((*a)->pos > len / 2)
			(*a)->moves = len - (*a)->pos;
		else if ((*a)->pos <= len / 2)
			(*a)->moves = (*a)->pos;
		*a = (*a)->next;
	}
	*a = head;
	head = *b;
	len = ft_lstsize(*b);
	while (*b)
	{
		if ((*b)->pos > len / 2)
			(*b)->moves = len - (*b)->pos;
		else if ((*b)->pos <= len / 2)
			(*b)->moves = (*b)->pos;
		*b = (*b)->next;
	}
	*b = head;
}

void	set_nodes(t_list **a, t_list **b)
{
	set_pos(a);
	set_pos(b);
	set_target(a, b);
	set_moves(a, b);
}
