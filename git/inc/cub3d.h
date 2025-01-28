/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:31:41 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/27 17:31:51 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <linux/input-event-codes.h>
# include "../libft/libft_pf_gnl.h"

/* typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_angle {
	float	y_rot_x;
	float	z_rot_x;
	float	x_rot_z;
	float	y_rot_z;
	float	x_rot_y;
	float	z_rot_y;
}				t_angle;

typedef struct s_map {
	int		altitude;
	int		color;
}			t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	char	*map_name;
	t_map	**map;
	int		x_max;
	int		y_max;
	int		offset_u;
	int		offset_v;
	int		zoom;
	int		angle;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	int		color_background;
	int		color_panel;
	int		color_fdf;
	int		gradient;
	int		min_z;
}	t_data;

typedef struct s_point {
	int		x;
	int		y;
	int		z;
	int		u;
	int		v;
	int		color;
}			t_point;

typedef struct s_node {
	int				z;
	int				u;
	int				v;
	struct s_node	*next;
}			t_node;

typedef struct s_liste {
	t_node	*head;
}	t_liste;
 */

#endif