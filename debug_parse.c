/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:07:36 by inbar             #+#    #+#             */
/*   Updated: 2025/02/05 16:54:52 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parse.h"

void    print_parsing(t_data *data)
{
    printf("\nCHECK:\n");
    printf("No: $%s$\n", data->no);
    printf("So: $%s$\n", data->so);
    printf("We: $%s$\n", data->we);
    printf("Ea: $%s$\n", data->ea);

    printf("F: $%d$\n", data->floor_clr);
    printf("C: $%d$\n", data->ceiling_clr);

    print_map(data->map);
}

void    print_map(char **map)
{
    int i;

    printf("\n####MAP####\n");
    i = 0;
    while (map[i] != NULL)
    {
        printf("%s$\n", map[i]);
        i++;
    }
    printf("#####MAP####\n\n");
}