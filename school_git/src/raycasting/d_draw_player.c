/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_draw_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:35:04 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/17 17:54:59 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_player(t_data *data)
{
	t_coord		coord;
	uint32_t	i;
	uint32_t	j;

	coord.x = data->player.x;
	coord.y = data->player.y;
	i = coord.y - TILE_SIZE / 8;
	while (i < coord.y + TILE_SIZE / 8)
	{
		j = coord.x - TILE_SIZE / 8;
		while (j < coord.x + TILE_SIZE / 8)
		{
			if (j < data->img->height && i < data->img->width)
				mlx_put_pixel(data->img, j, i, PLY_COL);
			j++;
		}
		i++;
	}
}
