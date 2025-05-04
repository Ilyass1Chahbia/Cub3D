/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:21:12 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/24 12:56:09 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	in_wall(t_stc *stc, float x, float y)
{
	int	i;
	int	j;
	int	last_char;

	i = (int)floor(y / (SZ_TILE));
	j = (int)floor(x / (SZ_TILE));
	if (i < 0 || i > stc->mpinf->lines)
		return (1);
	last_char = ft_strlen(stc->map[i]) - 1;
	if (j < 0 || j > last_char)
		return (1);
	if (stc->map[i][j] == '1')
		return (1);
	return (0);
}

void	update_player(t_stc *stc)
{
	float	new_x;
	float	new_y;
	float	walk;
	float	move;

	stc->player.rot_angle += stc->player.turn_d * stc->player.rot_speed;
	stc->player.rot_angle = ft_get_val(stc->player.rot_angle);
	walk = stc->player.walk_d * stc->player.pl_speed;
	new_x = stc->player.x + cos(stc->player.rot_angle) * walk;
	new_y = stc->player.y + sin(stc->player.rot_angle) * walk;
	move = stc->player.move_d * stc->player.pl_speed;
	new_x = new_x + cos(stc->player.rot_angle + (M_PI / 2)) * move;
	new_y = new_y + sin(stc->player.rot_angle + (M_PI / 2)) * move;
	if (!in_wall_2(stc, new_x, new_y))
	{
		stc->player.x = new_x;
		stc->player.y = new_y;
	}
}

void	change_pos(t_stc *stc)
{
	update_player(stc);
	ft_rays_casting(stc);
	ft_walls_render(stc);
	stc->player.turn_d = 0;
	stc->player.walk_d = 0;
	stc->player.move_d = 0;
}

int	ft_button(t_stc *stc)
{
	if (mlx_is_key_down(stc->mlx_pt, MLX_KEY_RIGHT))
		return (stc->player.turn_d = 0.5, 5);
	if (mlx_is_key_down(stc->mlx_pt, MLX_KEY_LEFT))
		return (stc->player.turn_d = -0.5, 6);
	if (mlx_is_key_down(stc->mlx_pt, MLX_KEY_ESCAPE))
		return (mlx_close_window(stc->mlx_pt), 0);
	if (mlx_is_key_down(stc->mlx_pt, MLX_KEY_D))
		return (stc->player.move_d = 1, 4);
	if (mlx_is_key_down(stc->mlx_pt, MLX_KEY_A))
		return (stc->player.move_d = -1, 2);
	if (mlx_is_key_down(stc->mlx_pt, MLX_KEY_W))
		return (stc->player.walk_d = 1, 1);
	if (mlx_is_key_down(stc->mlx_pt, MLX_KEY_S))
		return (stc->player.walk_d = -1, 3);
	return (0);
}

void	ft_move(void *st)
{
	t_stc	*stc;

	stc = (t_stc *)st;
	ft_button(stc);
	mlx_delete_image(stc->mlx_pt, stc->img_pt);
	stc->img_pt = mlx_new_image(stc->mlx_pt, WIN_WIDTH, WIN_HEIGHT);
	if (!stc->img_pt)
		return ;
	mlx_image_to_window(stc->mlx_pt, stc->img_pt, 0, 0);
	change_pos(stc);
}
