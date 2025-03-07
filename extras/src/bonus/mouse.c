/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:51:29 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/07 12:45:57 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


//adjust the player's angle based on mouse movement
void mouse_callback(double xpos, double ypos, void* param)
{
    static double last_x = 0;
    double delta_x = xpos - last_x;

    t_data *data = (t_data *)param;
    // mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
    if (xpos <= 0)
    {
        mlx_set_mouse_pos(data->mlx, data->mlx->width - 5, ypos);
        last_x = data->mlx->width - 5;
        return ;
    }
    if (xpos >= data->mlx->width - 1)
    {
        mlx_set_mouse_pos(data->mlx, 0, ypos);
        last_x = 0;
        return ;
    }
    data->player.angle_r -= (float)(delta_x * 0.002); // Adjust sensitivity
    // Normalize the angle to keep it between 0 and 2*PI
    data->player.angle_r = fmodf(data->player.angle_r, 2 * M_PI);
    if (data->player.angle_r < 0)
        data->player.angle_r += 2 * M_PI;
    last_x = xpos;
}
