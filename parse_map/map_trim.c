/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:01:22 by inbar             #+#    #+#             */
/*   Updated: 2025/02/07 13:05:13 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parse.h"

static int     get_min_start(t_data *data, int *min_start, int i);

//returns 1 if char is a player char
int     is_player(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}


//extracts player position and direction, returns error if found invalid character
//because of extracting player's position, should happen after trimming map lines
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
            if (is_player(c))
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
static int     get_min_start(t_data *data, int *min_start, int i)
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
