/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:47:34 by htharrau          #+#    #+#             */
/*   Updated: 2025/02/16 11:03:36 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void		handle_error(char *error_message, t_data *data);
int			close_window(void *param);

void	handle_error(char *error_message, t_data *data)
{
	ft_printf("Error: %s\n", error_message);
	close_window(data);
	exit(1);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	clean_parse((data));
	ft_printf("Exiting program...\n");
	exit(0);
	return (0);
}
