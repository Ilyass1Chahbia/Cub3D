/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:33:30 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/26 15:38:25 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_no(t_stc *stc, char *line, int *index)
{
	char	*path;

	if (stc->no)
		return (free(line), write(2, "Error\ndouble element\n", 22), 1);
	path = get_path(line, 0, 0, 0);
	if (path)
		stc->no = path;
	else
		return (free(line), write(2, "Error\ninvalid path\n", 20), 1);
	(*index)++;
	return (free(line), 0);
}

int	fill_so(t_stc *stc, char *line, int *index)
{
	char	*path;

	if (stc->so)
		return (free(line), write(2, "Error\ndouble element\n", 22), 1);
	path = get_path(line, 0, 0, 0);
	if (path)
		stc->so = path;
	else
		return (free(line), write(2, "Error\ninvalid path\n", 20), 1);
	(*index)++;
	return (free(line), 0);
}

int	fill_we(t_stc *stc, char *line, int *index)
{
	char	*path;

	if (stc->we)
		return (free(line), write(2, "Error\ndouble element\n", 22), 1);
	path = get_path(line, 0, 0, 0);
	if (path)
		stc->we = path;
	else
		return (free(line), write(2, "Error\ninvalid path\n", 20), 1);
	(*index)++;
	return (free(line), 0);
}

int	fill_ea(t_stc *stc, char *line, int *index)
{
	char	*path;

	if (stc->ea)
		return (free(line), write(2, "Error\ndouble element\n", 22), 1);
	path = get_path(line, 0, 0, 0);
	if (path)
		stc->ea = path;
	else
		return (free(line), write(2, "Error\ninvalid path\n", 20), 1);
	(*index)++;
	return (free(line), 0);
}

int	check_stc(char *stc)
{
	int	i;

	i = ft_strlen(stc) - 4;
	if (ft_strncmp(stc + i, ".cub", 4) == 0)
	{
		return (0);
	}
	else
		write(2, "Error\nfile extension Error\n", 28);
	return (1);
}
