/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_again_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:21 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/23 19:09:30 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_outline_2(t_stc *stc, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_put_pixel(stc->img_pt, x + i, y, color);
		mlx_put_pixel(stc->img_pt, x + i, y + 4 - 1, color);
		mlx_put_pixel(stc->img_pt, x, y + i, color);
		mlx_put_pixel(stc->img_pt, x + 4 - 1, y + i, color);
		i++;
	}
}

void	door_num(t_stc *stc)
{
	int	n;
	int	m;

	n = 0;
	while (stc->map[n])
	{
		m = 0;
		while (stc->map[n][m])
		{
			if (stc->map[n][m] == 'D')
				stc->n_d++;
			m++;
		}
		n++;
	}
	if (stc->n_d == 0)
		return ;
	stc->door.d_x = malloc(stc->n_d * sizeof(int));
	if (!(stc->door.d_x))
		return ;
	stc->door.d_y = malloc(stc->n_d * sizeof(int));
	if (!(stc->door.d_y))
		return (free(stc->door.d_x), (void)0);
}

void	vr_while(t_stc *stc, t_line *line, t_rp vs)
{
	while (vs.vz_x >= 0 && vs.vz_x < stc->nm_col * SZ_TILE
		&& vs.vz_y >= 0 && vs.vz_y < stc->nm_row * SZ_TILE)
	{
		vs.check_x = vs.vz_x;
		if (line->ray_left)
			vs.check_x -= 0.0062;
		vs.check_y = vs.vz_y;
		if (in_wall(stc, vs.check_x, vs.check_y))
		{
			line->vwall_x = vs.vz_x;
			line->vwall_y = vs.vz_y;
			line->vertical_hit = 1;
			if (in_wall(stc, vs.check_x, vs.check_y) == 2)
				line->tmp_v_cont = 1;
			else if (in_wall(stc, vs.check_x, vs.check_y) == 1)
				line->tmp_v_cont = 0;
			break ;
		}
		else
		{
			vs.vz_x += line->v_x;
			vs.vz_y += line->v_y;
		}
	}
}

void	hz_while(t_stc *stc, t_line *line, t_rp vs)
{
	while (vs.hz_x >= 0 && vs.hz_x < stc->nm_col * SZ_TILE
		&& vs.hz_y >= 0 && vs.hz_y < stc->nm_row * SZ_TILE)
	{
		vs.check_x = vs.hz_x;
		vs.check_y = vs.hz_y;
		if (line->ray_up)
			vs.check_y -= 0.0062;
		if (in_wall(stc, vs.check_x, vs.check_y))
		{
			line->hwall_x = vs.hz_x;
			line->hwall_y = vs.hz_y;
			line->horizontal_hit = 1;
			if (in_wall(stc, vs.check_x, vs.check_y) == 2)
				line->tmp_h_cont = 1;
			else if (in_wall(stc, vs.check_x, vs.check_y) == 1)
				line->tmp_h_cont = 0;
			break ;
		}
		else
		{
			vs.hz_x += line->h_x;
			vs.hz_y += line->h_y;
		}
	}
}
