/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:13:55 by ilazar            #+#    #+#             */
/*   Updated: 2025/01/31 16:34:34 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_PARSE_H
#define CUB3D_PARSE_H


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

#define PARSE_ERR         3
#define MALLOC_ERR        2
#define FAILURE           1
#define SUCCESS           0


typedef struct  s_data
{
    char    **map;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    int     floor_clr;
    int     ceiling_clr;
    int     player_x;   //player x position
    int     player_y;   //player y position
    int     w_map;      //map width;
    int     h_map;      //map hight;

}   t_data;


//map parsing

//elements
int         parse_elements(char *line, t_data *data, int found_map);


int         err_msg(char *msg, int err_nr);
void        init_data(t_data *data);
int         make_map(char *file_name, t_data *data);
char	    *get_next_line2(int fd);

//to be utils
int     ft_isspace(char c);
void	free_2d_char(char **arr);
int     line_empty(char *line);
char    *is_first_occurance(char *str, char c);
void    print_map(char **map);


#endif
