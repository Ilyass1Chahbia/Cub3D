/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_again.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:21 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/19 13:38:57 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			break ;
		}
		else
		{
			vs.vz_x += line->v_step_x;
			vs.vz_y += line->v_step_y;
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
			break ;
		}
		else
		{
			vs.hz_x += line->h_step_x;
			vs.hz_y += line->h_step_y;
		}
	}
}
