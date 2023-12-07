/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:19:16 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/03 11:03:02 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// contents: ra, rb, rr

// rotate a
t_list	**ra(t_list **node)
{
	t_list	*head;
	t_list	*last;

	if (node && node[0] && node[0]->next)
	{
		last = ft_lstlast(node[0]);
		head = node[0]->next;
		last->next = node[0];
		node[0]->next = NULL;
		node[0] = head;
	}
	write(1, "ra\n", 3);
	return (node);
}

// rotate b
t_list	**rb(t_list **node)
{
	t_list	*head;
	t_list	*last;

	if (node && node[1] && node[1]->next)
	{
		last = ft_lstlast(node[1]);
		head = node[1]->next;
		last->next = node[1];
		node[1]->next = NULL;
		node[1] = head;
	}
	write(1, "rb\n", 3);
	return (node);
}

// rotate both
t_list	**rr(t_list **node)
{
	return (ra(rb(node)));
}
