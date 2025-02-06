/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:01:22 by inbar             #+#    #+#             */
/*   Updated: 2025/02/06 15:39:31 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parse.h"

int     trim_lines(t_data *data);
int     get_min_start(t_data *data, int *min_start, int i);
int     valid_chars(t_data *data, int i, int j);

int     map_parser(t_data *data)
{
    int status;
    
    status = SUCCESS;
    
    status = trim_lines(data);
    if (status != SUCCESS)
        return (status);
    
    if (valid_chars(data, 0, 0) != SUCCESS)
        return (PARSE_ERR);
    
    status = valid_map(data);

    print_map(data->map);
    
    return (status);

}

int     check_space(char **map, int row, int col)
{
    //if col is not 0 -> leftside must be 1 or ' '
    //if row isnt last row -> line down must be 1 or ' ' or zero
    
    
    return (SUCCESS);
}

int     check_zero(char **map, int row, int col)
{
    // if col is not 0 -> leftside must be 1 or 0 or player
    // if row is not last one -> line down must be 1 or 0 or player
    
    
    return (SUCCESS);
}

int    valid_map(t_data *data)
{
    int     i;
    int     col;
    char    c;
    int     status;

    status = SUCCESS;
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
                status = check_space(data->map, i, col);
            else if (c == '0' || c <= 90 || c >= 65)
                status = check_zero(data->map, i, col);
        }
    }
    return (status);
}


//extracts player position and direction, returns error if found invalid character
//because of extracting players position, should happen after trimming map lines
int     valid_chars(t_data *data, int i, int j)
{
    char    c;

    i = 1;
    while (data->map[++i] != NULL)
    {
        j = -1;
        while (data->map[i][++j] != '\0')
        {
            c = data->map[i][j];
            if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
            {
                if (data->player_x != -1)
                    return (err_msg("Multiple players found in map :/", PARSE_ERR));
                data->player_x = j;
                data->player_y = i;
                data->player_dir = c;
                continue ;
            }
            if (c != ' ' && c != '1' && c != '0')
                return (err_msg("Map contains forbbiden character :/", PARSE_ERR));
        }
    }
    if (data->player_x != -1)
        return (SUCCESS);
    return (err_msg("No player found in map :/", PARSE_ERR));
}

//trims all spaces from the left and right sides of the map, trims \n
//saves map height
//may return malloc err or parse err
int     trim_lines(t_data *data)
{
    int min_start;
    int len;
    int i;
    char *tmp;

    min_start = 0;
    if (get_min_start(data, &min_start, 0) == PARSE_ERR)
        return (PARSE_ERR);
    i = -1;
    while (data->map[++i] != NULL)
    {
        len = ft_strlen(data->map[i]) - 1;
        while (data->map[i][len-1] == ' ')
            len--;
        tmp = ft_substr(data->map[i], min_start, len - min_start);
        if (tmp == NULL)
            return (MALLOC_ERR);
        free(data->map[i]);
        data->map[i] = ft_strdup(tmp);
        if (data->map[i] == NULL)
            return (MALLOC_ERR);
        free(tmp);
    }
    data->h_map = i;
    return (SUCCESS);
}

//find the leftmost start of the lines in the map array
//saves map width;
int     get_min_start(t_data *data, int *min_start, int i)
{
    int     start;
    int     end;
    int     max_end;
    char    *line_start;

    line_start = is_first_occurance(data->map[0], '1');
    if (line_start == NULL)
        return (PARSE_ERR);
    *min_start = line_start - data->map[0];
    max_end = ft_strlen(data->map[0]);
    i = 0;
    while (data->map[++i] != NULL)
    {
        line_start = is_first_occurance(data->map[i], '1');
        if (line_start == NULL)
            return (PARSE_ERR);
        start = line_start - data->map[i];
        if (start < *min_start)
            *min_start = start;
        end = ft_strlen(data->map[i]);
        if (end > max_end)
            max_end = end;
    }
    data->w_map = max_end;
    return (SUCCESS);
}

