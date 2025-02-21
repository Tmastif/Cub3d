/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:53:15 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/21 16:44:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// Convert texture to a displayable image and put on screen
void    convert_textures(t_data *data)
{
    mlx_image_t* img = mlx_texture_to_image(data->mlx, data->textures[WE]);
    if (!img)
        exit_err(data, "Converting Textures", FAILURE);

    if (mlx_image_to_window(data->mlx, img, 200, 250) < 0)
        printf("errorroor\n");
}

        /*
void    clean_textures(t_data *data)
{
    mlx_delete_texture(data->textures[NO]);
    if (data->textures)
    {
        if (data->textures[NO])
            free(data->textures[NO]);
        // if (data->textures[SO])
        //     free(data->textures[SO]);
        // if (data->textures[WE])
        //     free(data->textures[WE]);
        // if (data->textures[EA])
        //     free(data->textures[EA]);
        free(data->textures);
    }
}
*/