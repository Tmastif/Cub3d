/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:44:10 by inbar             #+#    #+#             */
/*   Updated: 2025/02/07 12:47:15 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parse.h"

static int     check_space(t_data *data, int row, int col);
static int     check_zero(t_data *data, int row, int col);
static int     check_top_bottom(t_data *data);

//returns SUCCESS if map is according to rules
int    valid_map(t_data *data, int status)
{
    int     i;
    int     col;
    char    c;
 
    status = check_top_bottom(data);
    i = -1;
    while (data->map[++i] != NULL && status == SUCCESS)
    {
        col = 0;
        while (data->map[i][col + 1] != '\0')
            col++;
        if (data->map[i][col] != '1')
            return (err_msg("Map contains open walls :/", PARSE_ERR));
        while (--col != 0 && status == SUCCESS)
        {
            c = data->map[i][col];
            if (c == '1')
                continue;
            else if (c == ' ')
                status = check_space(data, i, col);
            else if (c == '0' || is_player(c))
                status = check_zero(data, i, col);
        }
    }
    return (status);
}

//if col is not 0 -> leftside must be 1 or ' '
//if row isnt last row -> line down must be 1 or ' '
static int     check_space(t_data *data, int row, int col)
{
    char    **map;
    char    *msg;
    char    c;

    msg = "Map contains open walls :/";
    map = data->map;
    if (col != 0)
    {
        c = map[row][col - 1];
        if (c != '1' && c != ' ')
            return (err_msg(msg, PARSE_ERR));
    }    
    if (row != (data->h_map - 1))
    {
        c = map[row + 1][col];
        if (c != '1' && c != ' ')
            return (err_msg(msg, PARSE_ERR));
    }
    return (SUCCESS);
}

// if col is not 0 -> leftside must be 1 or 0 or player
// if row is not last one -> line down must be 1 or 0 or player
static int     check_zero(t_data *data, int row, int col)
{
    char    **map;
    char    *msg;
    char    c;

    msg = "Map contains open walls :/";
    map = data->map;
    if (col != 0)
    {
        c = map[row][col - 1];
        if (c != '1' && c != '0' && !is_player(c))
            return (err_msg(msg, PARSE_ERR));
    }
    if (row != data->h_map - 1)
    {
        c = map[row + 1][col];
        if (c != '1' && c != '0' && !is_player(c))
            return (err_msg(msg, PARSE_ERR));
    }
    return (SUCCESS);
}
//returns 1 if both top and bottom lines of the map contain only '1's or spaces
static int     check_top_bottom(t_data *data)
{
    int j;
    int bottom;

    j = -1;
    while (data->map[0][++j] != '\0')
    {
        if (data->map[0][j] != '1' && data->map[0][j] != ' ')
            return (err_msg("Map contains open walls :/", PARSE_ERR));
    }
    j = -1;
    bottom = data->h_map - 1;
    while (data->map[bottom][++j] != '\0')
    {
        if (data->map[bottom][j] != '1' && data->map[bottom][j] != ' ')
            return (err_msg("Map contains open walls :/", PARSE_ERR));
    }
    return (SUCCESS);
}
