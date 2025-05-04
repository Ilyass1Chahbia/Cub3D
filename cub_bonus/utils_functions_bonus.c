/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:01:29 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/23 19:09:40 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	mouse_move(t_stc *stc)
{
	int	ms_y;
	int	ms_x;

	ms_y = 0;
	ms_x = 0;
	mlx_get_mouse_pos(stc->mlx_pt, &ms_x, &ms_y);
	if (stc->mouse_x < ms_x)
		stc->player.rot_angle += 0.001 * (ms_x - stc->mouse_x);
	if (stc->mouse_x > ms_x)
		stc->player.rot_angle -= 0.001 * (stc->mouse_x - ms_x);
	if (stc->player.rot_angle > 2 * M_PI)
		stc->player.rot_angle -= 2 * M_PI;
	if (stc->player.rot_angle < 0)
		stc->player.rot_angle += 2 * M_PI;
	mlx_set_mouse_pos(stc->mlx_pt, (WIN_WIDTH / 2), (WIN_HEIGHT / 2));
	stc->mouse_x = (WIN_WIDTH / 2);
}

int	in_wall_2(t_stc *stc, float x, float y)
{
	if (stc->map[(int)floor((y + 10) / (SZ_TILE))]
		[(int)floor((x + 10) / (SZ_TILE))] == '1')
		return (1);
	if (stc->map[(int)floor((y - 10) / (SZ_TILE))]
		[(int)floor((x + 10) / (SZ_TILE))] == '1')
		return (1);
	if (stc->map[(int)floor((y + 10) / (SZ_TILE))]
		[(int)floor((x - 10) / (SZ_TILE))] == '1')
		return (1);
	if (stc->map[(int)floor((y - 10) / (SZ_TILE))]
		[(int)floor((x - 10) / (SZ_TILE))] == '1')
		return (1);
	return (0);
}

float	calc_dst(float x0, float y0, float x1, float y1)
{
	return (sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))));
}

float	ft_get_val(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle >= 2 * M_PI)
		angle -= (2 * M_PI);
	return (angle);
}

void	ft_casting(t_stc *stc, int id)
{
	hz_ray(stc, &(stc)->rays[id]);
	vr_ray(stc, &(stc)->rays[id]);
	find_walls(stc, &(stc)->rays[id]);
}
