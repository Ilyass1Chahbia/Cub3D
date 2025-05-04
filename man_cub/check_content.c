/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:07:13 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/26 15:24:44 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initial_imgs(t_stc *stc)
{
	int	i;

	i = 0;
	stc->img_no = NULL;
	stc->img_so = NULL;
	stc->img_ea = NULL;
	stc->img_we = NULL;
}

t_stc	*initialize_stc(void)
{
	t_stc	*stc;

	stc = malloc(sizeof(t_stc));
	if (!stc)
		return (NULL);
	stc->no = NULL;
	stc->so = NULL;
	stc->we = NULL;
	stc->ea = NULL;
	stc->map = NULL;
	stc->f[0] = -1;
	stc->f[1] = -1;
	stc->f[2] = -1;
	stc->c[0] = -1;
	stc->c[1] = -1;
	stc->c[2] = -1;
	stc->index = 0;
	stc->nm_row = 0;
	stc->nm_col = 0;
	stc->tmp_map = NULL;
	stc->mpinf = NULL;
	stc->rays = NULL;
	initial_imgs(stc);
	return (stc);
}

int	get_elements(char *ln, t_stc *stc, int *index)
{
	char	**elm;

	elm = ft_split(ln, ' ');
	if (!elm)
		return (free(ln), 1);
	if (!ft_strcmp("NO", elm[0]))
		return (ft_free(elm), fill_no(stc, ln, index));
	else if (!ft_strcmp("SO", elm[0]))
		return (ft_free(elm), fill_so(stc, ln, index));
	else if (!ft_strcmp("WE", elm[0]))
		return (ft_free(elm), fill_we(stc, ln, index));
	else if (!ft_strcmp("EA", elm[0]))
		return (ft_free(elm), fill_ea(stc, ln, index));
	else if (!ft_strcmp("F", elm[0]))
		return (free(ln), fill_f(stc, elm, index, NULL));
	else if (!ft_strcmp("C", elm[0]))
		return (free(ln), fill_c(stc, elm, index, NULL));
	else
		return (free(ln), ft_free(elm), write(2, "Error\ninvalid id\n", 18), 1);
}

int	check_empt(char *line)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] != 32) && (line[i] != '\n'))
			return (1);
		i++;
	}
	return (x);
}

int	check_line(char *line, t_stc *stc, int *i, char *linetrim)
{
	if (!ft_strcmp("\n", line) || !check_empt(line))
	{
		if (*i == 0)
			return (0);
		if (*i <= 5)
			return (0);
		if (*i > 5)
		{
			if (stc->index == 1)
				return ((write(2, "Error\nnewline in map\n", 22)), 1);
			else
				return (0);
		}
	}
	if (*i <= 5)
	{
		linetrim = ft_strtrim(line, "\n", 0, 0);
		if (!linetrim)
			return (1);
		return (get_elements(linetrim, stc, i));
	}
	else if (*i > 5 && map_components(line, stc, i))
		return (1);
	return (0);
}
