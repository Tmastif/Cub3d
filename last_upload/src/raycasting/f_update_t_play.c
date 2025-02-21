/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_update_t_play.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:58:59 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/17 16:50:39 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void			update_play(t_data *data);
static float	calculate_delta_x(t_data *data, t_player *player);
static float	calculate_delta_y(t_data *data, t_player *player);
static void		update_angle(t_data *data, t_player *player);
static bool		collision(t_data *data, float x, float y);

void	update_play(t_data *data)
{
	float	speed;
	float	delta_x;
	float	delta_y;
	float	new_x;
	float	new_y;

	new_x = data->player.x;
	new_y = data->player.y;
	update_angle(data, &data->player);
	delta_x = calculate_delta_x(data, &data->player);
	delta_y = calculate_delta_y(data, &data->player);
	speed = MVT_SPEED;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT_CONTROL) || 
		mlx_is_key_down(data->mlx, MLX_KEY_LEFT_CONTROL))
		speed *= 2;
	new_x += speed * delta_x;
	new_y += speed * delta_y;
	if (!collision(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!collision(data, data->player.x, new_y))
		data->player.y = new_y;
}

static float	calculate_delta_x(t_data *data, t_player *player)
{
	float	delta_x;

	delta_x = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) 
		delta_x += cosf(player->angle_r);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) 
		delta_x -= cosf(player->angle_r);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) 
		delta_x -= sinf(player->angle_r);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) 
		delta_x += sinf(player->angle_r);
	return (delta_x);
}

static float	calculate_delta_y(t_data *data, t_player *player)
{
	float	delta_y;

	delta_y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) 
		delta_y -= sinf(player->angle_r);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) 
		delta_y += sinf(player->angle_r);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) 
		delta_y -= cosf(player->angle_r);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) 
		delta_y += cosf(player->angle_r);
	return (delta_y);
}

static void	update_angle(t_data *data, t_player *player)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		player->angle_r += ROT_SPEED;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		player->angle_r -= ROT_SPEED;
	player->angle_r = fmod(player->angle_r + 2 * M_PI, 2 * M_PI);
}

static bool	collision(t_data *data, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)((x - OFFSET) / TILE_SIZE);
	map_y = (int)((y - OFFSET) / TILE_SIZE);
	if (map_x < 0 || map_x >= data->input.w_map 
		|| map_y < 0 || map_y >= data->input.h_map 
		|| (data->input.map[map_y][map_x] != '0'
		&& data->input.map[map_y][map_x] != 'N'
		&& data->input.map[map_y][map_x] != 'E'
		&& data->input.map[map_y][map_x] != 'W'
		&& data->input.map[map_y][map_x] != 'S'))
		return (true);
	return (false);
}
