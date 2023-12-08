/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:08:48 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/08 12:15:11 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	while (len > 3)
	{
		pb(a, b);
		len--;
	}
	set_nodes(a, b);
}