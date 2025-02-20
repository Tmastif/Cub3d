/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:53:15 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/20 16:22:31 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


//load png texture. if file is missing or corrupted will err msg and return null
mlx_texture_t      *load_png(t_data *data, char *path)
{
    mlx_texture_t *texture;
 
    (void)data;
	texture =  mlx_load_png(path);
	if (!texture)
    {
        // handle_error((char *)mlx_strerror(mlx_errno), data, FAILURE);
        ft_printf("%s failed to load\n", path);
        return (NULL);
    }
    return (texture);
}


void		load_textures(t_data *data)
{
	data->textures = (mlx_texture_t **) malloc(sizeof(mlx_texture_t *) * 4);
	if (!data->textures)
		handle_error("Malloc", data, MALLOC_ERR);
	data->textures[NO] = load_png(data, data->input.no);
	data->textures[SO] = load_png(data, data->input.so);
	data->textures[WE] = load_png(data, data->input.we);
	data->textures[EA] = load_png(data, data->input.ea);

    
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