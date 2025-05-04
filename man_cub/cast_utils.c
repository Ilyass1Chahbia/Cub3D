/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:15:57 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/16 15:29:27 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dst_check1(t_line *line)
{
	line->ind_x = line->vwall_x;
	line->ind_y = line->vwall_y;
	line->dst = line->dst_v;
	line->vertical_hit = 1;
	line->horizontal_hit = 0;
}

void	dst_check2(t_line *line)
{
	line->ind_x = line->hwall_x;
	line->ind_y = line->hwall_y;
	line->dst = line->dst_h;
	line->vertical_hit = 0;
	line->horizontal_hit = 1;
}
