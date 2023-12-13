/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:49:40 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/13 10:40:42 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_cases(int n, char *str)
{
	char	*min;
	int		i;

	i = 0;
	min = "-2147483648";
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (n == -2147483648)
	{
		while (min[i] != '\0')
		{
			str[i] = min[i];
			i++;
		}
		str[i] = '\0';
	}
}

static int	ft_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = ft_digits(n);
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (0);
	if (n == 0 || n == -2147483648)
	{
		ft_cases(n, s);
		return (s);
	}
	s[i--] = '\0';
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 0)
	{
		s[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (t1[i] == t2[i] && (t1[i] != 0 || t2[i] != 0) && i < n)
		i++;
	if (i == n)
		return (0);
	return (t1[i] - t2[i]);
}

int	check_max(int num, char *str)
{
	char	*n;

	n = ft_itoa(num);
	if (ft_strncmp(n, str, 100) != 0 && num != 0)
	{
		free(n);
		return (1);
	}
	free(n);
	return (0);
}
