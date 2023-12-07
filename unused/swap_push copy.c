/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:07:17 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/03 11:02:32 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// contents: sa, sb, ss, pa, pb

// swap a
t_list	**sa(t_list **node)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (node && node[0] && node[0]->next)
	{
		tmp1 = node[0];
		tmp2 = node[0]->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		node[0] = tmp2;
	}
	write(1, "sa\n", 3);
	return (node);
}

// swap b
t_list	**sb(t_list **node)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (node && node[1] && node[1]->next)
	{
		tmp1 = node[1];
		tmp2 = node[1]->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		node[1] = tmp2;
	}
	write(1, "sb\n", 3);
	return (node);
}

// swap both
t_list	**ss(t_list **node)
{
	return (sa(sb(node)));
}

// push from b to a
t_list	**pa(t_list **node)
{
	t_list	*tmp;

	if (node && node[1])
	{
		tmp = node[1]->next;
		node[1]->next = node[0];
		node[0] = node[1];
		node[1] = tmp;
	}
	write(1, "pa\n", 3);
	return (node);
}

// push from a to b
t_list	**pb(t_list **node)
{
	t_list	*tmp;

	if (node && node[0])
	{
		tmp = node[0]->next;
		node[0]->next = node[1];
		node[1] = node[0];
		node[0] = tmp;
	}
	write(1, "pb\n", 3);
	return (node);
}