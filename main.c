/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:12:03 by ilazar            #+#    #+#             */
/*   Updated: 2025/01/30 14:32:35 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main to test map validation

#include "cub3d_parse.h"

int main(int ac, char **av)
{
    t_data  data;
    
    if (ac != 2)
        return (err_msg("Invalid argument number", PARSE_ERR));

    init_data(&data);

    //may return malloc err
    if (make_map(av[1], &data) == SUCCESS)
        printf("success\n");
    
    //clean data

    return (0);
}