/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:57:54 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/19 12:52:08 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// mlx_set_setting(MLX_STRETCH_IMAGE, true);
int	main(int ac, char **av)
{
	t_data	data;
	int		status;

	if (ac != 2)
		return (err_msg("Invalid argument number", PARSE_ERR));
	init_data((&data));
	
	//may return malloc err
	status = parser(av[1], &data);
	if (status != SUCCESS)
		return (status);
	print_input(&data.input);
	
	
	init_mlx(&data);
	mlx_image_to_window((&data)->mlx, (&data)->img, 0, 0);
	print_data((&data));
	// mlx_close_hook((&data)->mlx, &close_window, &data);
	mlx_loop_hook((&data)->mlx, &hoop_func, &data);
	mlx_key_hook((&data)->mlx, &escape, &data);
	mlx_loop((&data)->mlx);
	mlx_terminate((&data)->mlx);
	clean_parse((&data));
	return (0);
}


