/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:29:46 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/13 17:51:24 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	ft_free2(char **str, int y)
{
	int	i;

	i = 0;
	if (str)
	{
		while (i < y)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

size_t	countwords(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

char	*fillword(size_t *x, const char *s, char c)
{
	char	*str;
	size_t	i;
	size_t	wordsize;
	size_t	sw;

	i = 0;
	sw = 0;
	while (s[*x] != '\0' && s[*x] == c)
		(*x)++;
	sw = *x;
	while (s[*x] != '\0' && s[*x] != c)
		(*x)++;
	wordsize = *x - sw;
	str = (char *)malloc(((wordsize + 1) * sizeof(char)));
	if (!str)
		return (NULL);
	while (sw + i < *x)
	{
		str[i] = s[sw + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	y;
	size_t	x;
	char	**arr;

	y = 0;
	x = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc((countwords(s, c) + 1) * sizeof (char *));
	if (!arr)
		return (NULL);
	while (y < countwords(s, c))
	{
		arr [y] = fillword(&x, s, c);
		if (!arr[y])
		{
			ft_free2(arr, y);
			return (NULL);
		}
		y++;
	}
	arr[countwords(s, c)] = 0;
	return (arr);
}
