/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:00:55 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/08 12:11:50 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	node = ft_lstlast(node);
	node->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (!content)
	{
		node->content = 0;
		node->next = NULL;
		return (node);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lst(int *n, unsigned int len)
{
	t_list			*lst;
	unsigned int	i;

	i = 0;
	if (len >= 1)
		lst = ft_lstnew(n[i++]);
	while (i < len)
		ft_lstadd_back(&lst, ft_lstnew(n[i++]));
	return (lst);
}

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_putnbr((int)lst->content);
		write(1, " ", 1);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	write(1, "\n", 1);
}
