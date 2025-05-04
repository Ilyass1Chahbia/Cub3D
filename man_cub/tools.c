/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:26:40 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/26 15:24:54 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((s1[i] && !s2[i]) || (!s1[i] && s2[i]))
		return (1);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	return (str1[i] - str2[i]);
}

char	*ft_strdup1(char *s1)
{
	char	*tmps;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	tmps = malloc(len + 2);
	if (!tmps)
		return (NULL);
	tmps[i++] = '.';
	while (s1[j])
	{
		tmps[i] = s1[j];
		i++;
		j++;
	}
	tmps[i] = '\0';
	return (tmps);
}

char	*ft_strtrim(char *s1, char *set, int i, int start)
{
	int		trmlen;
	int		end;
	char	*trmstr;

	if (!s1 || !set)
		return (NULL);
	if (s1[ft_strlen(s1) - 2] == ' ')
		return (write(2, "Error\nspc at the end\n", 22), NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]) != 0)
		start++;
	while (end > start && ft_strchr(set, s1[end]) != 0)
		end--;
	trmlen = end - start + 1;
	trmstr = (char *)malloc((trmlen + 1) * sizeof(char));
	if (!trmstr)
		return (NULL);
	while (trmlen > i)
		trmstr[i++] = s1[start++];
	trmstr[i] = '\0';
	return (trmstr);
}

int	check_range(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (1);
	if (s[i] == ',')
		return (1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ',')
			return (1);
		if (s[i] == ',' && s[i + 1] == ',')
			return (1);
		i++;
	}
	if (s[i - 1] == ',')
		return (1);
	return (0);
}
