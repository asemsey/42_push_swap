/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:47:47 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/08 12:14:43 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_target(t_list **a, t_list *b_node)
{
	t_list	*head;
	t_list	*target;

	head = *a;
	target = *a;
	while (*a)
	{
		if ((*a)->content > b_node->content && (*a)->content - b_node->content < target->content - b_node->content)
			target = *a;
		if (!(*a)->next)
			break ;
		*a = (*a)->next;
	}
	*a = head;
	return (target);
}

void	set_target(t_list **a, t_list **b)
{
	t_list	*head;

	head = *b;
	while (*b)
	{
		(*b)->target = get_target(a, *b);
		if (!(*b)->next)
			break ;
		*b = (*b)->next;
	}
	*b = head;
}

void	set_pos(t_list **a, t_list **b)
{
	t_list	*head;
	int		p;

	head = *a;
	p = 0;
	while (*a)
	{
		(*a)->pos = p++;
		if (!(*a)->next)
			break ;
		*a = (*a)->next;
	}
	*a = head;
	head = *b;
	p = 0;
	while (*b)
	{
		(*b)->pos = p++;
		if (!(*b)->next)
			break ;
		*b = (*b)->next;
	}
	*b = head;
}

void	set_nodes(t_list **a, t_list **b)
{
	set_pos(a, b);
	set_target(a, b);
}
