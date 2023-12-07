/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:24:01 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/03 11:03:33 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// contents: rra, rrb, rrr

// reverse rotate a
t_list	**rra(t_list **node)
{
	t_list	*head;
	t_list	*last;
	t_list	*new_last;

	if (node && node[0] && node[0]->next)
	{
		head = node[0];
		last = ft_lstlast(node[0]);
		new_last = node[0];
		while (new_last && new_last->next && new_last->next->next)
			new_last = new_last->next;
		new_last->next = NULL;
		last->next = head;
		node[0] = last;
	}
	write(1, "rra\n", 4);
	return (node);
}

// reverse rotate b
t_list	**rrb(t_list **node)
{
	t_list	*head;
	t_list	*last;
	t_list	*new_last;

	if (node && node[1] && node[1]->next)
	{
		head = node[1];
		last = ft_lstlast(node[1]);
		new_last = node[1];
		while (new_last && new_last->next && new_last->next->next)
			new_last = new_last->next;
		new_last->next = NULL;
		last->next = head;
		node[1] = last;
	}
	write(1, "rrb\n", 4);
	return (node);
}

// reverse rotate both
t_list	**rrr(t_list **node)
{
	return (rra(rrb(node)));
}
