/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_draw_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:43:47 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/17 17:55:59 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void		draw_fov(mlx_image_t *img, t_player *player);
static void	line(mlx_image_t *img, int x, int y, float angle);

void	draw_fov(mlx_image_t *img, t_player *player)
{
	float	i;

	i = player->angle_r - M_PI / 6;
	while (i < player->angle_r + M_PI / 6)
	{
		line(img, (int)(player->x), (int)(player->y), i);
		i = i + 0.04;
	}
}

static void	line(mlx_image_t *img, int x, int y, float angle)
{
	int	i;
	int	u;
	int	v;
	int	length;

	i = 0;
	length = TILE_SIZE * 7;
	while (i < length)
	{
		u = x + i * cos(angle);
		v = y - i * sin(angle);
		if (u > 0 && v > 0 && u < (int)img->width && v < (int)img->height)
			mlx_put_pixel(img, u, v, LIME);
		i++;
	}
}
