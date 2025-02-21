/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:43:48 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/21 17:10:50 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//get appropriate texture for wall orientation
mlx_texture_t 	*get_texture_orient(t_data *data, t_ray *ray)
{
	mlx_texture_t	*texture;
	
	if (ray->wall_orient == EAST)
		texture = data->textures[EA];
	if (ray->wall_orient == WEST)
	texture = data->textures[WE];
		if (ray->wall_orient == NORTH)
	texture = data->textures[NO];
	if (ray->wall_orient == SOUTH)
		texture = data->textures[SO];
	return (texture);
}

//calculate the x-coordinate on the texture
int		calc_texture_x(t_ray *ray, mlx_texture_t *texture)
{
	int	tex_x;
	
	tex_x = (int)(ray->wall_x * texture->width) % texture->width; // (if wall_x is bigger than 1 or for repetition)
	if ((ray->wall_orient == EAST && ray->cos_angle > 0) ||
        (ray->wall_orient == NORTH && ray->sin_angle < 0))
        tex_x = texture->width - tex_x - 1;
    return (tex_x);
}

//sample pixel from texture and correct bytes order
uint32_t	sample_color(t_texture *texture)
{
	uint32_t		color;
	uint32_t		raw_color;
	mlx_texture_t	*png;
	int				tex_x;
	int				tex_y;

	tex_x = texture->tex_x;
	tex_y = texture->tex_y;
	png = texture->png;	
	raw_color = ((uint32_t*)png->pixels)[tex_y * png->width + tex_x];
	color = ((raw_color & 0xFF) << 24) | ((raw_color & 0xFF00) << 8) |
            ((raw_color & 0xFF0000) >> 8) | ((raw_color & 0xFF000000) >> 24);
	return (color);
}