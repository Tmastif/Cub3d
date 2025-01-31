/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:56:14 by ilazar            #+#    #+#             */
/*   Updated: 2025/01/31 16:37:22 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d_parse.h"

void    init_data(t_data *data)
{
    data->map = NULL;
    data->no = NULL;
    data->so = NULL;
    data->we = NULL;
    data->ea = NULL;
    data->floor_clr = -1;
    data->ceiling_clr = -1;
    data->player_x = -1;
    data->player_y = -1;
    data->w_map = -1;
    data->h_map = -1;
}