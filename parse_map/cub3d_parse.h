/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:13:55 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/07 13:05:32 by inbar            ###   ########.fr       */
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
    char    player_dir; //player direction
    int     w_map;      //map width
    int     h_map;      //map hight

}   t_data;


//map parsing

//elements
int         parse_elements(char *line, t_data *data, int found_map);


int         err_msg(char *msg, int err_nr);
void        init_data(t_data *data);
int         parser(char *file_name, t_data *data);
char	    *get_next_line2(int fd);

//map parser
int         map_parser(t_data *data);

//map trim
int         trim_lines(t_data *data);
int         valid_chars(t_data *data, int i, int j);
int         is_player(char c);

//map rules
int         valid_map(t_data *data, int status);

//utils parse
int         ft_isspace(char c);
void	    free_2d_char(char **arr);
int         line_empty(char *line);
char        *is_first_occurance(char *str, char c);
void        clean_parse(t_data *data);

//debug parse
void        print_parsing(t_data *data);
void        print_map(char **map);


#endif
