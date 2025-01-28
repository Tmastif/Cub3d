

#ifndef CUB3D_H
#define CUB3D_H


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

#define PARSE_ERR 2
#define FAILURE 1
#define SUCCESS 0


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
int         err_msg(char *msg, int err_nr);
void        init_data(t_data *data);
int         make_map(char *file_name, t_data *data);
char	*get_next_line2(int fd);


#endif
