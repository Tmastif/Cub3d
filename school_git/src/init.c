/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:56:14 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/19 17:44:43 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->img = NULL;
	data->input.map = NULL;
	data->input.w_map = -1;
	data->input.h_map = -1;
	data->input.so = NULL;
	data->input.we = NULL;
	data->input.ea = NULL;
	data->input.no = NULL;
	data->input.floor = -1;
	data->input.sky = -1;
	data->input.play_x = -1;
	data->input.play_y = -1;
	data->input.cardinal = '0';
	data->player.x = 0;
	data->player.y = 0;
	data->player.angle_r = 0;
	data->textures = NULL;
}

// int		init_textures(t_data *data)
// {
// 	data->textures = (int **) malloc(sizeof(int *));
// 	if (!data->textures)
// 		handle_error("Malloc", data, MALLOC_ERR);
// 	data->textures[NO] = xpm_to_img(data, data->input->no);
	
// }
