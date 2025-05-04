/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:40:54 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/24 13:09:39 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_stc	*get_stc(char *map, int i, int fd)
{
	t_stc	*stc;
	char	*line;

	stc = initialize_stc();
	if (!stc)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nmap not found\n", 21), free(stc), NULL);
	line = get_next_line(fd);
	if (line == NULL)
		return (write(2, "Error\nempty map\n", 17), close(fd), free(stc), NULL);
	if (check_line(line, stc, &i, NULL))
		return (close(fd), clean_stc(stc), free(line), NULL);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_line(line, stc, &i, NULL))
			return (close(fd), free(line), clean_stc(stc), NULL);
	}
	close(fd);
	return (stc);
}

void	render_game(t_stc *stc, int n, int m, float x)
{
	float	y;

	y = 0;
	while (n < stc->nm_row)
	{
		m = 0;
		while (m <= ft_strlen(stc->map[n]) - 1)
		{
			x = m * SZ_TILE;
			y = n * SZ_TILE;
			if (stc->map[n][m] == 'N' || stc->map[n][m] == 'S'
				|| stc->map[n][m] == 'E' || stc->map[n][m] == 'W')
			{
				stc->player.x = x + (SZ_TILE / 2);
				stc->player.y = y + (SZ_TILE / 2);
			}
			m++;
		}
		n++;
	}
}

t_mapinfos	*intial_mpinfos(t_stc *stc)
{
	char		**tmp_map;
	t_mapinfos	*mpinfos;

	mpinfos = malloc(sizeof(t_mapinfos));
	if (!mpinfos)
		return (NULL);
	mpinfos->pi_lc = 0;
	mpinfos->ni_lc = 0;
	mpinfos->lines = 0;
	mpinfos->j = 0;
	mpinfos->lc = 0;
	tmp_map = ft_split(stc->tmp_map, '\n');
	if (!tmp_map)
		return (NULL);
	while (tmp_map[mpinfos->lines])
		mpinfos->lines++;
	mpinfos->lines--;
	ft_free(tmp_map);
	return (mpinfos);
}

int	start_game(t_stc *stc)
{
	t_char			pl;
	mlx_t			*mlx_ptr;
	mlx_image_t		*img_ptr;

	mlx_ptr = mlx_init(WIN_WIDTH, WIN_HEIGHT, "CUB_BONUS", false);
	img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (init_char(&pl, stc, mlx_ptr, img_ptr))
		return (mlx_delete_image(mlx_ptr, img_ptr),
			mlx_close_window(mlx_ptr), 1);
	render_game(stc, 0, 0, 0);
	door_num(stc);
	door_coords(stc);
	if (load_gun(stc))
		return (mlx_delete_image(mlx_ptr, img_ptr),
			mlx_close_window(mlx_ptr), 1);
	mlx_set_cursor_mode(mlx_ptr, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(stc->mlx_pt, &(stc)->mouse_x, &(stc)->mouse_y);
	mlx_loop_hook(mlx_ptr, ft_move, stc);
	mlx_loop(mlx_ptr);
	mlx_delete_image(mlx_ptr, img_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_stc		*stc;
	t_mapinfos	*mpinfos;

	stc = NULL;
	if (ac == 2)
	{
		if (check_stc(av[1]))
			return (1);
		stc = get_stc(av[1], 0, 0);
		if (!stc)
			return (1);
		mpinfos = intial_mpinfos(stc);
		if (!mpinfos)
			return (clean_stc(stc), free(mpinfos), 1);
		stc->mpinf = mpinfos;
		if (check_nplayer(stc) || check_map(stc, 0, mpinfos))
			return (write(2, "Error\nMap Not Valid\n", 21), clean_stc(stc), 1);
		if (start_game(stc))
			return (clean_stc(stc), 1);
	}
	else
		write(2, "Error\nno map / to much args\n", 29);
	clean_stc(stc);
	return (0);
}
