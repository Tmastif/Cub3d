/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_dda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:57:58 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/17 17:54:23 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void		dda(t_data *data, t_ray *ray);
static void	calcul_dist_per_unit(t_ray *ray);
static void	init_position_dist(t_data *data, t_ray *ray);
static void	find_wall(t_data *data, t_ray *ray);
static void	wall_check(t_data *data, t_ray *ray, bool *wall);

void	dda(t_data *data, t_ray *ray)
{
	calcul_dist_per_unit(ray);
	init_position_dist(data, ray);
	find_wall(data, ray);
}

// Calculate hypotenuse lengths, avoiding division by zero
// LENGTH OF THE RAY FOR ONE GRID CELL - x + 1 = ray + hypo_x
static void	calcul_dist_per_unit(t_ray *ray)
{
	if (ray->cos_angle == 0)
		ray->hypo_x = MAX_DIST;
	else
		ray->hypo_x = fabsf(1 / ray->cos_angle);
	if (ray->sin_angle == 0)
		ray->hypo_y = MAX_DIST;
	else
		ray->hypo_y = fabsf(1 / ray->sin_angle);
}

// INIT POSITION - in int for the DDA + FIRST DISTANCE 
static void	init_position_dist(t_data *data, t_ray *ray)
{
	ray->map_x = (int)((data->player.x - OFFSET) / TILE_SIZE);
	ray->map_y = (int)((data->player.y - OFFSET) / TILE_SIZE);
	if (ray->cos_angle > 0) 
	{
		ray->dist_x = (ray->map_x + 1 - (data->player.x - OFFSET) / TILE_SIZE) 
			* ray->hypo_x;
	}
	else 
	{
		ray->dist_x = ((data->player.x - OFFSET) / TILE_SIZE - ray->map_x) 
			* ray->hypo_x;
	}
	if (ray->sin_angle < 0) 
	{
		ray->dist_y = (ray->map_y + 1 - (data->player.y - OFFSET) / TILE_SIZE) 
			* ray->hypo_y;
	}
	else 
	{
		ray->dist_y = ((data->player.y - OFFSET) / TILE_SIZE - ray->map_y) 
			* ray->hypo_y;
	}
}

// FINDING WALLS: the DDA
static void	find_wall(t_data *data, t_ray *ray)
{
	bool	wall;

	wall = 0;
	while (wall == 0) 
	{
		if (ray->dist_x < ray->dist_y)
		{
			ray->dist_x += ray->hypo_x;
			ray->map_x += ray->step_x;
			if (ray->step_x > 0)
				ray->wall_orient = EAST;
			else 
				ray->wall_orient = WEST;
		}
		else 
		{
			ray->dist_y += ray->hypo_y;
			ray->map_y += ray->step_y;
			if (ray->step_y > 0)
				ray->wall_orient = NORTH;
			else 
				ray->wall_orient = SOUTH;
		}
		wall_check(data, ray, &wall);
	}
}

// Check if ray has hit a wall or out of bound
static void	wall_check(t_data *data, t_ray *ray, bool *wall)
{
	if (ray->map_x < 0 || ray->map_x >= data->input.w_map 
		|| ray->map_y < 0 || ray->map_y >= data->input.h_map 
		|| data->input.map[ray->map_y][ray->map_x] == '1') 
		*wall = 1;
}
