/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls_rend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:27:09 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/27 15:07:11 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	up_and_down(t_stc *stc, int id)
{
	int	n;

	n = 0;
	while (n < WIN_HEIGHT)
	{
		if (n < WIN_HEIGHT / 2)
			mlx_put_pixel(stc->img_pt, id, n,
				ft_rgb(stc->c[0], stc->c[1], stc->c[2], 255));
		if (n > WIN_HEIGHT / 2)
			mlx_put_pixel(stc->img_pt, id, n,
				ft_rgb(stc->f[0], stc->f[1], stc->f[2], 255));
		n++;
	}
}

uint32_t	to_rgba(uint32_t color)
{
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;

	b = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	r = color & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

void	loop_draw(t_stc *stc, t_var *vars, int offsety, int id)
{
	int				disftop;
	unsigned int	color;
	unsigned int	*img_pexel;
	mlx_image_t		*tmp_img;

	while (vars->n < vars->bottom_g)
	{
		disftop = vars->n + (vars->stripheight / 2) - (WIN_HEIGHT / 2);
		vars->img_h = get_img_height(stc, stc->rays[id].ray_ang, id);
		offsety = disftop * ((float) vars->img_h / vars->stripheight);
		tmp_img = get_img_pexel(stc, stc->rays[id].ray_ang, id);
		img_pexel = (unsigned int *)tmp_img->pixels;
		color = to_rgba(img_pexel[(tmp_img->width * offsety) + vars->offsetx]);
		mlx_put_pixel(stc->img_pt, id, vars->n, color);
		vars->n++;
	}
}

void	ft_draw_wall(t_stc *stc, int id, int stripheight)
{
	t_var	vars;

	vars.top_g = (WIN_HEIGHT / 2) - (stripheight / 2);
	vars.bottom_g = (WIN_HEIGHT / 2) + (stripheight / 2);
	if (vars.top_g < 0)
		vars.top_g = 0;
	if (vars.bottom_g > WIN_HEIGHT)
		vars.bottom_g = WIN_HEIGHT;
	vars.stripheight = stripheight;
	vars.x = stc->rays[id].ind_x;
	vars.y = stc->rays[id].ind_y;
	get_offset_x(stc, &vars, id);
	loop_draw(stc, &vars, 0, id);
}

void	ft_walls_render(t_stc *stc)
{
	int		id;
	float	fov;
	int		str_hg;

	id = 0;
	fov = 60 * (M_PI / 180);
	while (id < WIN_WIDTH)
	{
		str_hg = (SZ_TILE / (stc->rays[id].dst
					* cos(stc->rays[id].ray_ang - stc->player.rot_angle)))
			* ((WIN_WIDTH / 2) / tan(fov / 2));
		up_and_down(stc, id);
		ft_draw_wall(stc, id, str_hg);
		id++;
	}
}
