/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:43:52 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/17 17:56:20 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void		draw_minimap(t_data *data);
static void	draw_tiles(mlx_image_t *img, t_coord coord, int size, uint32_t col);

void	draw_minimap(t_data *data)
{
	t_coord	coord;
	int		x;
	int		y;

	y = 0;
	while (y < data->input.h_map)
	{
		x = 0;
		while (x < data->input.w_map)
		{
			coord.x = x * TILE_SIZE + OFFSET;
			coord.y = y * TILE_SIZE + OFFSET;
			if (data->input.map[y][x] == '1')
				draw_tiles(data->img, coord, TILE_SIZE, TILE_COL);
			else if (data->input.map[y][x] == '0' 
				|| data->input.map[y][x] == data->input.cardinal)
				draw_tiles(data->img, coord, TILE_SIZE, FLOOR_COL);
			x++;
		}
		y++;
	}
}

static void	draw_tiles(mlx_image_t *img, t_coord coord, int size, uint32_t col)
{
	uint32_t	i;
	uint32_t	j;

	i = coord.y;
	while (i < coord.y + size)
	{
		j = coord.x;
		while (j < coord.x + size)
		{
			if (j < img->height && i < img->width)
				mlx_put_pixel(img, j, i, col);
			j++;
		}
		i++;
	}
}
