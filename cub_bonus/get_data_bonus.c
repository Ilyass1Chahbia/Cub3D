/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:14:06 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/23 19:09:14 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	get_img_width(t_stc *stc, float ray_ang, int id)
{
	int	v_hit;
	int	h_hit;

	v_hit = stc->rays[id].vertical_hit;
	h_hit = stc->rays[id].horizontal_hit;
	if ((ray_ang >= 0 && ray_ang <= M_PI / 2) && v_hit == 1)
		return (stc->img_ea->width);
	else if ((ray_ang >= 0 && ray_ang <= M_PI / 2) && h_hit == 1)
		return (stc->img_so->width);
	else if ((ray_ang > M_PI / 2 && ray_ang <= M_PI) && v_hit == 1)
		return (stc->img_we->width);
	else if ((ray_ang > M_PI / 2 && ray_ang <= M_PI) && h_hit == 1)
		return (stc->img_so->width);
	else if ((ray_ang > M_PI && ray_ang <= (3 * M_PI / 2) && v_hit == 1))
		return (stc->img_we->width);
	else if ((ray_ang > M_PI && ray_ang <= (3 * M_PI / 2) && h_hit == 1))
		return (stc->img_no->width);
	else if ((ray_ang > (3 * M_PI / 2) && ray_ang <= (2 * M_PI) && v_hit == 1))
		return (stc->img_ea->width);
	else if ((ray_ang > (3 * M_PI / 2) && ray_ang <= (2 * M_PI) && h_hit == 1))
		return (stc->img_no->width);
	return (-1);
}

int	get_img_height(t_stc *stc, float ray_ang, int id)
{
	int	v_hit;
	int	h_hit;

	v_hit = stc->rays[id].vertical_hit;
	h_hit = stc->rays[id].horizontal_hit;
	if ((ray_ang >= 0 && ray_ang <= M_PI / 2) && v_hit == 1)
		return (stc->img_ea->height);
	else if ((ray_ang >= 0 && ray_ang <= M_PI / 2) && h_hit == 1)
		return (stc->img_so->height);
	else if ((ray_ang > M_PI / 2 && ray_ang <= M_PI) && v_hit == 1)
		return (stc->img_we->height);
	else if ((ray_ang > M_PI / 2 && ray_ang <= M_PI) && h_hit == 1)
		return (stc->img_so->height);
	else if ((ray_ang > M_PI && ray_ang <= (3 * M_PI / 2) && v_hit == 1))
		return (stc->img_we->height);
	else if ((ray_ang > M_PI && ray_ang <= (3 * M_PI / 2) && h_hit == 1))
		return (stc->img_no->height);
	else if ((ray_ang > (3 * M_PI / 2) && ray_ang <= (2 * M_PI) && v_hit == 1))
		return (stc->img_ea->height);
	else if ((ray_ang > (3 * M_PI / 2) && ray_ang <= (2 * M_PI) && h_hit == 1))
		return (stc->img_no->height);
	return (-1);
}

mlx_image_t	*get_img_pexel(t_stc *stc, float ray_ang, int id)
{
	int	v_hit;
	int	h_hit;

	v_hit = stc->rays[id].vertical_hit;
	h_hit = stc->rays[id].horizontal_hit;
	if ((ray_ang >= 0 && ray_ang <= M_PI / 2) && v_hit == 1)
		return (stc->img_ea);
	else if ((ray_ang >= 0 && ray_ang <= M_PI / 2) && h_hit == 1)
		return (stc->img_so);
	else if ((ray_ang > M_PI / 2 && ray_ang <= M_PI) && v_hit == 1)
		return (stc->img_we);
	else if ((ray_ang > M_PI / 2 && ray_ang <= M_PI) && h_hit == 1)
		return (stc->img_so);
	else if ((ray_ang > M_PI && ray_ang <= (3 * M_PI / 2) && v_hit == 1))
		return (stc->img_we);
	else if ((ray_ang > M_PI && ray_ang <= (3 * M_PI / 2) && h_hit == 1))
		return (stc->img_no);
	else if ((ray_ang > (3 * M_PI / 2) && ray_ang <= (2 * M_PI) && v_hit == 1))
		return (stc->img_ea);
	else if ((ray_ang > (3 * M_PI / 2) && ray_ang <= (2 * M_PI) && h_hit == 1))
		return (stc->img_no);
	return (NULL);
}

void	get_offset_x(t_stc *stc, t_var *vars, int id)
{
	if (stc->rays[id].vertical_hit)
	{
		if (vars->check == 1)
			vars->img_w = stc->img_d->width;
		else
			vars->img_w = get_img_width(stc, stc->rays[id].ray_ang, id);
		if (vars->img_w < 0)
			return (mlx_delete_image(stc->mlx_pt, stc->img_pt),
				mlx_close_window(stc->mlx_pt), clean_stc(stc), exit(1));
		vars->offsetx = (int)((vars->y / SZ_TILE) * vars->img_w) % vars->img_w;
	}
	else
	{
		if (vars->check == 1)
			vars->img_w = stc->img_d->width;
		else
			vars->img_w = get_img_width(stc, stc->rays[id].ray_ang, id);
		if (vars->img_w < 0)
			return (mlx_delete_image(stc->mlx_pt, stc->img_pt),
				mlx_close_window(stc->mlx_pt), clean_stc(stc), exit(1));
		vars->offsetx = (int)((vars->x / SZ_TILE) * vars->img_w) % vars->img_w;
	}
	vars->n = vars->top_g;
}
