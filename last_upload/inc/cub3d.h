/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:14:51 by htharrau          #+#    #+#             */
/*   Updated: 2025/03/06 16:27:19 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define CYAN 0x00FFFFFF
# define MAGENTA 0xFF00FFFF
# define GRAY 0x808080FF
# define ORANGE 0xFFA500FF
# define PURPLE 0x800080FF
# define BROWN 0xA52A2AFF
# define PINK 0xFFC0CBFF
# define LIME 0x00FF00FF
# define TEAL 0x008080FF
# define NAVY 0x000080FF

# define M_PI 3.14159265358979323846
# define MAX_DIST 1e6

# define WIDTH 800
# define HEIGHT 600

# define OFFSET 10
# define TILE_SIZE 12
# define MVT_SPEED 1.2
# define ROT_SPEED 0.05
# define FOV 66
# define WALL_SIZE 3

//Minimap colors
# define PLY_COL MAGENTA
# define TILE_COL PINK
# define FLOOR_COL ORANGE
# define BACK_COL NAVY
# define RAY_COL LIME

//status states
# define PARSE_ERR	3
# define MALLOC_ERR	2
# define FAILURE	1
# define SUCCESS	0

//Walls
# define NORTH	0
# define WEST	1
# define SOUTH	2
# define EAST	3

//Wall default colors
# define CLR_NORTH	TEAL
# define CLR_WEST	ORANGE
# define CLR_SOUTH	PURPLE
# define CLR_EAST	GRAY


# include <math.h>
# include <time.h>
# include <linux/input-event-codes.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_input {
	char	**map;
	int		w_map;
	int		h_map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		sky;
	int		play_x;
	int		play_y;
	char	cardinal; //player direction
}		t_input;

typedef struct s_player {
	float	x;
	float	y;
	float	angle_r;
}		t_player;

typedef struct s_data {
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_input			input;
	t_player		player;
	mlx_texture_t	**textures;
}		t_data;

typedef struct s_ray {
	float 	cos_angle;
	float	sin_angle;
	int 	map_x;
	int		map_y;
	float	dist_x;
	float	dist_y;
	float	hypo_x;
	float	hypo_y;
	int 	step_x;
	int		step_y;
	int		line_length;
	uint	wall_orient; 	//S N E W
	float	wall_x; 		//exact hit point on the wall
	
}		t_ray;

typedef struct s_texture {
	mlx_texture_t	*png;
	int				tex_x; //x coordinate on the texture
	int				tex_y; //y coordinate on the texture
	uint32_t		color;
}		t_texture;


typedef struct s_coord {
	float	x;
	float	y;
}		t_coord;




/******************************************************************************/
/******************************************************************************/
/*								PARSING										  */
/******************************************************************************/
/******************************************************************************/

//elements
int		parse_elements(char *line, t_data *data, int found_map);
void	init_data(t_data *data);
int		parser(char *file_name, t_data *data);
// char	*get_next_line2(int fd);

//trim right
int		trim_lines(t_data *data);
int		trim_rightend(t_data *data);

//trim left
int		trim_leftend(t_data *data);

//valid chars
int		valid_chars(t_data *data, int i, int j);

//valid map
int		valid_map(t_data *data, int status);

//utils parse
int		ft_isspace(char c);
void	free_2d_char(char **arr);
int		line_empty(char *line);
char	*is_first_occurance(char *str, char c);
void	clean_parse(t_data *data);

/******************************************************************************/
/******************************************************************************/
/*								RAYCASTING									  */
/******************************************************************************/
/******************************************************************************/

void	init_mlx(t_data *data);
void	hoop_func(void *param);
void	draw_minimap(t_data *data);
void	draw_player(t_data *data);
void	draw_fov(mlx_image_t *img, t_player *player);
void	update_play(t_data *data);
void	cast_rays(t_data *data);
void	dda(t_data *data, t_ray *ray);
void	escape(mlx_key_data_t keys, void *param);
float	degree_to_rad(int nb);
void	handle_error(char *error_message, t_data *data, int exit_status);
void	close_window(void *param, int exit_status);
float	degree_to_rad(int nb);

/******************************************************************************/
/******************************************************************************/
/*									TEXTURES								  */
/******************************************************************************/
/******************************************************************************/

void			load_textures(t_data *data);
uint32_t		sample_color(t_texture *texture);
int				calc_texture_x(t_ray *ray, mlx_texture_t *texture);
int 			use_default_clr(uint wall_orient);
void    		clean_textures(t_data *data);

/******************************************************************************/
/******************************************************************************/
/*									OTHER									  */
/******************************************************************************/
/******************************************************************************/

void	print_player(t_player *player);
void	print_input(t_input *input);
void	print_data(t_data *data);
int		err_msg(char *msg, int err_nr);
void	exit_err(t_data *data, char *msg, int exit_status);


//BONUS
void 	mouse_callback(double xpos, double ypos, void* param);


#endif

/******************************************************************************/
/************************MLX STRUCT WE ARE USING*******************************/
/******************************************************************************/

/*
// main MLX handle, which you'll use to initialize and manage your window.
typedef struct mlx
{
	void*		window;  //The window itself.
	void*		context;  //Abstracted opengl data.
	int32_t		width;  //The width of the window.
	int32_t		height; //The height of the window.
	float		delta_time; // time diff bw the previous and the current frame. 
}		mlx_t;

// to create and manage textures for walls, sprites, and other game elements
// To handle the main rendering buffer for your game
// Any value can be modified except the width/height and context.
typedef struct mlx_image
{
	const uint32_t	width; //The width of the image.
	const uint32_t	height; //The height of the image.
	uint8_t*		pixels; //The literal pixel data.
	mlx_instance_t*	instances; //instance carrying the X, Y and Z location data.
	size_t			count; //The element count of the instances array.
	bool			enabled; //If true the image is drawn onto the screen, else it's not.
	void*			context; //Abstracted OpenGL data.
}		mlx_image_t;

// might be useful for managing multiple instances of sprites / repeating elmts
// An image instance can be summarized as just a simple x, y & z coordinate.
 * NOTE: To change the z value, use mlx_set_instance_depth!
typedef struct mlx_instance
{
	int32_t	x; //The x location.
	int32_t	y; //The y location.
	int32_t	z; //The z depth, controls if the image is on the fore or background
	bool	enabled; //If true, the instance is drawn, else it's not.
}		mlx_instance_t;



// Base object for disk loaded textures. contains rudementary information about the texture.
typedef struct mlx_texture
{
	uint32_t	width; //The width of the texture.
	uint32_t	height; //The height of the texture.
	uint8_t		bytes_per_pixel; //The literal pixel data.
	uint8_t*	pixels; //The amount of bytes in a pixel, always 4.
}		mlx_texture_t;

// Struct containing data regarding an XPM image.
typedef struct xpm
{
	mlx_texture_t	texture; //The texture data of the XPM.
	int32_t			color_count; //The amount of colors available.
	int32_t			cpp; //The amount of characters per pixel.
	char			mode; //The color mode, either (c)olor or (m)onochrome.
}		xpm_t;


********************************************************************************
*******************************************************************************/