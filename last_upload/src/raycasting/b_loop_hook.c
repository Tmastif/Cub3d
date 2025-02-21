/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_loop_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:43:01 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/17 14:38:53 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void			hoop_func(void *param);
static void		draw_ceiling_floor(t_data *data);

void	hoop_func(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	update_play(data);
	draw_ceiling_floor(data);
	cast_rays(data);
	draw_minimap(data);
	draw_player(data);
	draw_fov(data->img, &data->player);
}

static void	draw_ceiling_floor(t_data *data)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < data->mlx->height / 2)
	{
		j = 0;
		while (j < data->mlx->width)
		{
			mlx_put_pixel(data->img, j, i, data->input.sky);
			j++;
		}
		i++;
	}
	while (i < data->mlx->height)
	{
		j = 0;
		while (j < data->mlx->width)
		{
			mlx_put_pixel(data->img, j, i, data->input.floor);
			j++;
		}
		i++;
	}
}
