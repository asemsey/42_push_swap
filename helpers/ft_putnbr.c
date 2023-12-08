/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:33 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/08 12:11:33 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_cases(int nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
}

void	ft_putnbr(int n)
{
	char	str[12];
	int		i;

	i = 0;
	if (n == 0 || n == -2147483648)
	{
		ft_cases(n);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
	}
}
