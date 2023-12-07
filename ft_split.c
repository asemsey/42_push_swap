/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:28:00 by asemsey           #+#    #+#             */
/*   Updated: 2023/11/30 15:37:31 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wordcount(const char *str, char c)
{
	int	words;

	words = 0;
	while (str && *str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			words++;
		while (*str && *str != c)
			str++;
	}
	return (words);
}

static char	*ft_substr(const char *str, char c)
{
	int		i;
	char	*s;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str && str[i] && str[i] != c)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i++] = NULL;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**strs;
	int		v[2];

	v[0] = wordcount(str, c);
	strs = (char **)malloc(sizeof(char *) * (v[0] + 1));
	if (!strs)
		return (NULL);
	v[1] = 0;
	while (v[1] < v[0])
	{
		while (str && *str && *str == c)
			str++;
		strs[v[1]++] = ft_substr(str, c);
		if (!strs[v[1] - 1])
			return (free_all(strs));
		while (str && *str && *str != c)
			str++;
	}
	strs[v[1]] = NULL;
	return (strs);
}
