/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:44:39 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/23 19:14:49 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_components(char *line, t_stc *stc, int *index)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != '\n')
			return ((write(2, "Error\ninvalid map component\n", 29)), 1);
		i++;
	}
	if (stc->tmp_map != NULL)
		tmp = stc->tmp_map;
	stc->tmp_map = ft_strjoin(stc->tmp_map, line);
	free(tmp);
	if (!stc->tmp_map)
		return (1);
	stc->index = 1;
	(*index)++;
	return (0);
}

int	fill_imgs(t_stc *stc, mlx_texture_t *ig, int index)
{
	if (index == 0)
	{
		stc->img_no = mlx_texture_to_image(stc->mlx_pt, ig);
		if (!stc->img_no)
			return (write(2, "Error\n invalid texture\n", 20), 1);
	}
	if (index == 1)
	{
		stc->img_so = mlx_texture_to_image(stc->mlx_pt, ig);
		if (!stc->img_so)
			return (write(2, "Error\n invalid texture\n", 20), 1);
	}
	if (index == 2)
	{
		stc->img_ea = mlx_texture_to_image(stc->mlx_pt, ig);
		if (!stc->img_ea)
			return (write(2, "Error\n invalid texture\n", 20), 1);
	}
	if (index == 3)
	{
		stc->img_we = mlx_texture_to_image(stc->mlx_pt, ig);
		if (!stc->img_we)
			return (write(2, "Error\n invalid texture\n", 20), 1);
	}
	return (mlx_delete_texture(ig), 0);
}

int	get_images(t_stc *stc, int i, mlx_texture_t *ig)
{
	while (++i < 4)
	{
		if (i == 0)
			ig = mlx_load_png(stc->no);
		else if (i == 1)
			ig = mlx_load_png(stc->so);
		else if (i == 2)
			ig = mlx_load_png(stc->ea);
		else if (i == 3)
			ig = mlx_load_png(stc->we);
		if (!ig)
			return (write(2, "Error\ninvalid img\n", 18), 1);
		if (fill_imgs(stc, ig, i) == 1)
			return (1);
	}
	return (0);
}

float	get_angle(char c)
{
	if (c == 'N')
		return ((3 * M_PI / 2));
	else if (c == 'S')
		return ((M_PI / 2));
	else if (c == 'W')
		return (M_PI);
	return (0);
}

int	init_char(t_char *pl, t_stc *stc, mlx_t *mlx_ptr, mlx_image_t *img_ptr)
{
	pl->x = SZ_TILE / 2;
	pl->y = SZ_TILE / 2;
	pl->rad = 5;
	pl->turn_d = 0;
	pl->walk_d = 0;
	pl->move_d = 0;
	pl->rot_angle = get_angle(stc->r);
	pl->pl_speed = 10;
	pl->rot_speed = 10 * (M_PI / 180);
	stc->player = *pl;
	stc->mlx_pt = mlx_ptr;
	stc->img_pt = img_ptr;
	stc->fire = 0;
	stc->rays = malloc(NM_RAYS * sizeof(t_line));
	if (!(stc->rays))
		return (1);
	if (get_images(stc, -1, NULL))
		return (1);
	return (0);
}
