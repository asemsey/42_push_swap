/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:00:55 by asemsey           #+#    #+#             */
/*   Updated: 2023/11/30 14:16:05 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
