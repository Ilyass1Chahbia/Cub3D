/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:15:57 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/23 19:08:19 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	dst_check1(t_line *line)
{
	line->ind_x = line->vwall_x;
	line->ind_y = line->vwall_y;
	line->dst = line->dst_v;
	line->vertical_hit = 1;
	line->horizontal_hit = 0;
	line->wall_cont = line->tmp_v_cont;
}

void	dst_check2(t_line *line)
{
	line->ind_x = line->hwall_x;
	line->ind_y = line->hwall_y;
	line->dst = line->dst_h;
	line->vertical_hit = 0;
	line->horizontal_hit = 1;
	line->wall_cont = line->tmp_h_cont;
}
