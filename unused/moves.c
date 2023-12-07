/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:26:17 by asemsey           #+#    #+#             */
/*   Updated: 2023/11/30 10:27:56 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap
t_list	*swap(t_list *node)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (node && node->next)
	{
		tmp1 = node;
		tmp2 = node->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		node = tmp2;
	}
	write(1, "	swap ok\n", 10);
	return (node);
}

// reverse rotate
t_list	*r_rotate(t_list *node)
{
	t_list	*head;
	t_list	*last;
	t_list	*new_last;

	if (!node || !node->next)
		return (node);
	head = node;
	last = ft_lstlast(node);
	new_last = node;
	while (new_last && new_last->next && new_last->next->next)
		new_last = new_last->next;
	new_last->next = NULL;
	last->next = head;
	write(1, "	r_rotate ok\n", 14);
	return (last);
}

// rotate
t_list	*rotate(t_list *node)
{
	t_list	*head;
	t_list	*last;

	if (!node || !node->next)
		return (node);
	last = ft_lstlast(node);
	head = node->next;
	last->next = node;
	node->next = NULL;
	write(1, "	rotate ok\n", 12);
	return (head);
}

// push a
t_list	**push_a(t_list **node)
{
	t_list	*tmp;

	if (!node || !node[0])
		return (node);
	tmp = node[0]->next;
	node[0]->next = node[1];
	node[1] = node[0];
	node[0] = tmp;
	write(1, "	push ok\n", 10);
	return (node);
}

// push b
t_list	**push_b(t_list **node)
{
	t_list	*tmp;

	if (!node || !node[1])
		return (node);
	tmp = node[1]->next;
	node[1]->next = node[0];
	node[0] = node[1];
	node[1] = tmp;
	write(1, "	push ok\n", 10);
	return (node);
}


// int main(void)
// {
// 	t_list	**head;
// 	int		i;

// 	head = malloc(sizeof(t_list *) * 2);

// 	//make list 1
// 	write(1, "list 1: ", 9);
// 	i = 1;
// 	head[0] = ft_lstnew(i++);
// 	while (i <= 2)
// 		ft_lstadd_back(&head[0], ft_lstnew(i++));
// 	ft_lstprint(head[0]);

// 	//make list 2
// 	write(1, "list 2: ", 9);
// 	i = 1;
// 	head[1] = ft_lstnew(i++);
// 	while (i <= 1)
// 		ft_lstadd_back(&head[1], ft_lstnew(i++));
// 	ft_lstprint(head[1]);

// 	//tests
// 	write(1, "making changes...\n", 20);
// 	head = push_b(head);
// 	head[0] = rotate(head[0]);
// 	write(1, "list 1: ", 9);
// 	ft_lstprint(head[0]);
// 	write(1, "list 2: ", 9);
// 	ft_lstprint(head[1]);
// 	return (0);
// }
