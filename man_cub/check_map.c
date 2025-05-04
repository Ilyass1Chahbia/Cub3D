/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:06:31 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/29 14:59:18 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_nplayer(t_stc *stc)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	count = 0;
	tmp = stc->tmp_map;
	if (tmp[ft_strlen(tmp) - 1] == '\n')
		return (write(2, "Error\n newline at the end of map\n", 34), 1);
	while (tmp[i])
	{
		if (tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'E' || tmp[i] == 'W')
		{
			stc->r = tmp[i];
			count++;
		}
		i++;
	}
	if (count > 1 || count == 0)
		return (write(2, "Error\n no player /too many playres\n", 36), 1);
	return (0);
}

int	check_side(char c)
{
	if ((c == '0' || c == 'D' || c == 'N'
			|| c == 'S' || c == 'E' || c == 'W'))
		return (1);
	return (0);
}

int	check_door(char **row, int i, int j, t_mapinfos *mpi)
{
	int	lc;

	lc = ft_strlen(row[i]) - 1;
	if (i == 0 || j == 0 || j == lc || i == mpi->lines)
		return (write(2, "Error\ninvalid door\n", 20), 1);
	if ((j > 0 && row[i][j - 1] == '1') && (j < lc && (row[i][j + 1] == '1')))
	{
		if ((j < mpi->ni_lc && check_side(row[i + 1][j]))
			&& ((j < mpi->pi_lc && check_side(row[i - 1][j]))))
			return (0);
	}
	if ((j < mpi->ni_lc && row[i + 1][j] == '1')
		&& (j < mpi->pi_lc && row[i - 1][j] == '1'))
	{
		if ((j > 0 && check_side(row[i][j - 1]))
			&& (j < lc && check_side(row[i][j + 1])))
			return (0);
	}
	return (write(2, "Error\ninvalid door\n", 20), 1);
}

int	check_row(char **row, int i, t_stc *stc, t_mapinfos *mi)
{
	while (row[i][mi->j])
	{
		mi->lc = ft_strlen(row[i]) - 1;
		if (row[i][mi->j] == '0' || row[i][mi->j] == 'N' || row[i][mi->j] == 'S'
		|| row[i][mi->j] == 'E' || row[i][mi->j] == 'W')
		{
			if (mi->j == 0 || mi->j == mi->lc || mi->j > mi->pi_lc
				|| mi->j > mi->ni_lc)
				return (1);
			if (mi->j > 0 && (row[i][mi->j - 1] == ' '))
				return (1);
			if (mi->j < mi->lc && (row[i][mi->j + 1] == ' '))
				return (1);
			if (i > 0 && mi->j < mi->pi_lc && (row[i - 1][mi->j] == ' '))
				return (1);
			if (i < mi->lines && mi->j < mi->ni_lc && row[i + 1][mi->j] == ' ')
				return (1);
		}
		else if (row[i][mi->j] == 'D' && check_door(row, i, mi->j, mi))
			return (1);
		mi->j++;
	}
	if (stc->nm_col < mi->j)
		stc->nm_col = mi->j;
	return (0);
}

int	check_map(t_stc *stc, int i, t_mapinfos *mpinfos)
{
	char	**tmp;

	tmp = ft_split(stc->tmp_map, '\n');
	if (!tmp)
		return (1);
	while (tmp[i])
	{
		if (i < mpinfos->lines)
		{
			while (tmp[i + 1][mpinfos->ni_lc])
				mpinfos->ni_lc++;
			mpinfos->ni_lc--;
		}
		if (check_row(tmp, i, stc, mpinfos))
			return (ft_free(tmp), 1);
		mpinfos->j--;
		mpinfos->pi_lc = mpinfos->j;
		mpinfos->ni_lc = 0;
		mpinfos->j = 0;
		i++;
	}
	stc->nm_row = i;
	stc->map = tmp;
	return (0);
}
