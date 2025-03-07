/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_cleanup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:47:34 by htharrau          #+#    #+#             */
/*   Updated: 2025/03/06 13:27:32 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


//i changed it a bit - inbar

void	handle_error(char *error_message, t_data *data, int exit_status)
{
	ft_printf("Error: %s\n", error_message);
	close_window(data, exit_status);
}

void	close_window(void *param, int exit_status)
{
	t_data	*data;

	data = (t_data *)param;
	clean_parse(data);
	ft_printf("Exiting program...\n");
	exit(exit_status);
}
