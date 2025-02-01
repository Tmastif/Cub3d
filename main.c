/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:12:03 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/01 17:16:08 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main to test map validation

#include "cub3d_parse.h"

int main(int ac, char **av)
{
    t_data  data;
    int     status;
    
    if (ac != 2)
        return (err_msg("Invalid argument number", PARSE_ERR));

    init_data(&data);

    //may return malloc err
    status = parser(av[1], &data);
    if (status == SUCCESS)
        printf("success\n");
    
    //clean data

    return (status);
}