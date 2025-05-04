/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_cast_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:35:37 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/23 19:08:59 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	vr_ray(t_stc *stc, t_line *line)
{
	t_rp	vs;

	line->vertical_hit = 0;
	line->vwall_x = 0;
	line->vwall_y = 0;
	vs.inter_x = floor(stc->player.x / SZ_TILE) * SZ_TILE;
	if (line->ray_right)
		vs.inter_x += SZ_TILE;
	vs.inter_y = stc->player.y + (vs.inter_x - stc->player.x)
		* tan(line->ray_ang);
	line->v_x = SZ_TILE;
	line->v_y = SZ_TILE * tan(line->ray_ang);
	if (line->ray_left)
		line->v_x *= -1;
	if (line->ray_up && line->v_y > 0)
		line->v_y *= -1;
	if (line->ray_down && line->v_y < 0)
		line->v_y *= -1;
	vs.vz_x = vs.inter_x;
	vs.vz_y = vs.inter_y;
	vr_while(stc, line, vs);
}

void	hz_ray(t_stc *stc, t_line *line)
{
	t_rp	vs;

	line->horizontal_hit = 0;
	line->hwall_x = 0;
	line->hwall_y = 0;
	vs.inter_y = floor(stc->player.y / SZ_TILE) * SZ_TILE;
	if (line->ray_down)
		vs.inter_y += SZ_TILE;
	vs.inter_x = stc->player.x + (vs.inter_y
			- stc->player.y) / tan(line->ray_ang);
	line->h_y = SZ_TILE;
	if (line->ray_up)
		line->h_y *= -1;
	line->h_x = SZ_TILE / tan(line->ray_ang);
	if (line->ray_left && line->h_x > 0)
		line->h_x *= -1;
	if (line->ray_right && line->h_x < 0)
		line->h_x *= -1;
	vs.hz_x = vs.inter_x;
	vs.hz_y = vs.inter_y;
	hz_while(stc, line, vs);
}

void	find_walls(t_stc *stc, t_line *line)
{
	if (line->horizontal_hit)
		line->dst_h = calc_dst(stc->player.x,
				stc->player.y, line->hwall_x, line->hwall_y);
	else
		line->dst_h = 2147483647;
	if (line->vertical_hit)
		line->dst_v = calc_dst(stc->player.x,
				stc->player.y, line->vwall_x, line->vwall_y);
	else
		line->dst_v = 2147483647;
	if (line->dst_v < line->dst_h)
	{
		dst_check1(line);
	}
	else
	{
		dst_check2(line);
	}
}

t_line	ft_ray_init(float r_angle)
{
	t_line	line;

	line.dst = 0;
	line.ray_ang = ft_get_val(r_angle);
	line.ray_down = 0;
	if (line.ray_ang < M_PI && line.ray_ang > 0)
		line.ray_down = 1;
	line.ray_right = 0;
	if (line.ray_ang < (M_PI / 2) || line.ray_ang > (3 * M_PI / 2))
		line.ray_right = 1;
	line.vertical_hit = 0;
	line.ray_up = !(line.ray_down);
	line.ray_left = !(line.ray_right);
	line.hwall_x = 0;
	line.hwall_y = 0;
	line.vwall_x = 0;
	line.vwall_y = 0;
	line.ind_x = 0;
	line.ind_y = 0;
	line.h_x = 0;
	line.h_y = 0;
	line.dst_h = 0;
	line.dst_v = 0;
	return (line);
}

void	ft_rays_casting(t_stc *stc)
{
	int		id;
	float	r_angle;

	id = 0;
	r_angle = stc->player.rot_angle - (30 * (M_PI / 180));
	while (id < WIN_WIDTH)
	{
		stc->rays[id] = ft_ray_init(r_angle);
		ft_casting(stc, id);
		r_angle += (60 * (M_PI / 180)) / WIN_WIDTH;
		id++;
	}
}
