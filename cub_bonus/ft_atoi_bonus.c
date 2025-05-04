/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:09:00 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/26 15:58:13 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str, unsigned long result)
{
	int	i;
	int	sign;

	sign = 1;
	i = ft_spaces(str);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (sign == -1)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result > 255 && sign == 1))
			return (-1);
		i++;
	}
	return (result * sign);
}

void	free_img(t_stc *stc)
{
	int	i;

	i = 0;
	if (stc->img_d)
		mlx_delete_image(stc->mlx_pt, stc->img_d);
	if (stc->img_no)
		mlx_delete_image(stc->mlx_pt, stc->img_no);
	if (stc->img_so)
		mlx_delete_image(stc->mlx_pt, stc->img_so);
	if (stc->img_ea)
		mlx_delete_image(stc->mlx_pt, stc->img_ea);
	if (stc->img_we)
		mlx_delete_image(stc->mlx_pt, stc->img_we);
	while (i < 9)
	{
		if (stc->an[i])
			mlx_delete_image(stc->mlx_pt, stc->an[i]);
		i++;
	}
}

void	clean_stc(t_stc *stc)
{
	if (!stc)
		return ;
	if (stc->no)
		free(stc->no);
	if (stc->so)
		free(stc->so);
	if (stc->we)
		free(stc->we);
	if (stc->ea)
		free(stc->ea);
	if (stc->tmp_map)
		free(stc->tmp_map);
	if (stc->map)
		ft_free(stc->map);
	if (stc->mpinf)
		free(stc->mpinf);
	if (stc->door.d_x)
		free(stc->door.d_x);
	if (stc->door.d_y)
		free(stc->door.d_y);
	if (stc->rays)
		free(stc->rays);
	free_img(stc);
	free(stc);
}
