/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate_func_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:05:56 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/24 13:05:41 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

mlx_texture_t	*get_texture(int i)
{
	mlx_texture_t	*ig;

	ig = NULL;
	if (i == 0)
		ig = mlx_load_png("./images/gun/fr1.png");
	else if (i == 1)
		ig = mlx_load_png("./images/gun/fr2.png");
	else if (i == 2)
		ig = mlx_load_png("./images/gun/fr3.png");
	else if (i == 3)
		ig = mlx_load_png("./images/gun/fr4.png");
	else if (i == 4)
		ig = mlx_load_png("./images/gun/fr5.png");
	else if (i == 5)
		ig = mlx_load_png("./images/gun/fr6.png");
	else if (i == 6)
		ig = mlx_load_png("./images/gun/fr7.png");
	else if (i == 7)
		ig = mlx_load_png("./images/gun/fr8.png");
	else if (i == 8)
		ig = mlx_load_png("./images/gun/fr9.png");
	return (ig);
}

int	load_gun(t_stc *stc)
{
	int				i;
	mlx_texture_t	*ig;

	i = 0;
	while (i < 9)
	{
		stc->an[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 9)
	{
		ig = get_texture(i);
		if (!ig)
			return (write(2, "Error\ninvalid gun img\n", 23), 1);
		stc->an[i] = mlx_texture_to_image(stc->mlx_pt, ig);
		if (!stc->an[i])
			return (write(2, "Error\ninvalid gun texture\n", 27), 1);
		mlx_delete_texture(ig);
		i++;
	}
	return (0);
}

void	draw_gun(t_stc *stc, int fps, int x, int y)
{
	int				start_x;
	int				start_y;
	unsigned int	*img_pixel;
	unsigned int	clr_pxl;

	start_x = (WIN_WIDTH / 2) - (stc->an[fps]->height / 2);
	start_y = WIN_HEIGHT - stc->an[fps]->height;
	img_pixel = (unsigned int *)stc->an[fps]->pixels;
	while (y < (int) stc->an[fps]->height)
	{
		x = 0;
		while (x < (int) stc->an[fps]->width)
		{
			clr_pxl = img_pixel[y * stc->an[fps]->width + x];
			if (clr_pxl > 0)
			{
				clr_pxl = to_argb(img_pixel[y * stc->an[fps]->width + x]);
				mlx_put_pixel(stc->img_pt, start_x + x, start_y + y, clr_pxl);
			}
			x++;
		}
		y++;
	}
}

void	render_gun(t_stc *stc)
{
	static int	fps;

	if (stc->fire)
	{
		usleep(90000);
		draw_gun(stc, fps, 0, 0);
		fps++;
		if (fps >= 8)
		{
			fps = 0;
			stc->fire = 0;
		}
	}
	else
	{
		draw_gun(stc, fps, 0, 0);
	}
}
