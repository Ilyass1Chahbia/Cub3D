/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:01:29 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/16 16:01:52 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
