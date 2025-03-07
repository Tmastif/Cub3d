/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:25:58 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/18 18:02:47 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_player(t_player *player);
void	print_input(t_input *input);
void	print_data(t_data *data);

void	print_player(t_player *player)
{
	printf("\n=== PLAYER INFO ===\n");
	printf("Position: (%.2f, %.2f)\n", player->x, player->y);
	printf("Angle radian: %.2f\n", player->angle_r);
}

void	print_input(t_input *input)
{
	int	i;

	printf("\n=== INPUT INFO ===\n");
	printf("Map Dimensions: %d x %d\n", input->w_map, input->h_map);
	printf("Textures:\n");
	printf("  North: %s\n", input->no);
	printf("  South: %s\n", input->so);
	printf("  West: %s\n", input->we);
	printf("  East: %s\n", input->ea);
	printf("Colors:\n");
	printf("  Floor: %#x\n", input->floor);
	printf("  Ceiling: %#x\n", input->sky);
	printf("Player:\n");
	printf("  (x, y): (%d, %d)\n", input->play_x, input->play_y);
	printf("  Facing: %c\n", input->cardinal);
	printf("\nMap:\n");
	i = 0;
	while (i < input->h_map)
	{
		printf("%s$\n", input->map[i]);
		i++;
	}
}

void	print_data(t_data *data)
{
	printf("\n=== GAME DATA ===\n");
	printf("Window dimensions: %d x %d\n", data->mlx->width, data->mlx->height);
	print_input(&data->input);
	print_player(&data->player);
}
