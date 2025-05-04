/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:09:12 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/16 16:00:55 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_rgb(char **range, t_stc *stc, int option)
{
	int	i;
	int	num;

	i = 0;
	while (i < 3)
	{
		num = ft_atoi(range[i], 0);
		if (num < 0)
			return (write(2, "Error\ninvalid range\n", 21), 1);
		else
		{
			if (option == 1)
				stc->f[i++] = num;
			else if (option == 2)
				stc->c[i++] = num;
		}
	}
	return (0);
}

int	fill_f(t_stc *stc, char **elms, int *index, char **range)
{
	if (stc->f[0] != -1)
		return (ft_free(elms), write(2, "Error\ndouble element\n", 22), 1);
	if (elms[1] != NULL && elms[2] == NULL)
	{
		if (check_range(elms[1]))
			return (ft_free(elms), write(2, "Error\ninvalid RGB\n", 19), 1);
		range = ft_split(elms[1], ',');
		if (!range)
			return (ft_free(elms), ft_free(range), 1);
		if (range[3] != NULL)
		{
			ft_free(range);
			return (ft_free(elms), write(2, "Error\ninvlid RGB\n", 18), 1);
		}
		else
		{
			if (fill_rgb(range, stc, 1))
				return (ft_free(elms), ft_free(range), 1);
		}
	}
	else
		return (write(2, "Error\ninvalid RGB syntax\n", 26), ft_free(elms), 1);
	(*index)++;
	return (ft_free(elms), ft_free(range), 0);
}

int	fill_c(t_stc *stc, char **elms, int *index, char **range)
{
	if (stc->c[0] != -1)
		return (ft_free(elms), write(2, "Error\ndouble element\n", 22), 1);
	if (elms[1] != NULL && elms[2] == NULL)
	{
		if (check_range(elms[1]))
			return (ft_free(elms), write(2, "Error\ninvalid RGB\n", 19), 1);
		range = ft_split(elms[1], ',');
		if (!range)
			return (ft_free(elms), ft_free(range), 1);
		if (range[3] != NULL)
		{
			ft_free(range);
			return (ft_free(elms), write(2, "Error\ninvlid RGB\n", 18), 1);
		}
		else
		{
			if (fill_rgb(range, stc, 2))
				return (ft_free(elms), ft_free(range), 1);
		}
	}
	else
		return (write(2, "Error\ninvalid RGB syntax\n", 26), ft_free(elms), 1);
	(*index)++;
	return (ft_free(elms), ft_free(range), 0);
}

int	ft_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
