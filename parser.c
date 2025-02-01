/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:11:28 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/01 17:18:27 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//map validation

#include "cub3d_parse.h"
#include "get_next_line_bonus.h"
#include "gnl.h"


int     elements_finder(int fd, t_data *data, int status);
int     save_map(int fd, t_data *data, char **line, int *found_map);
char    **add_line_to_arr(char **map, char *line, int *length);

static int valid_map_file(char *name, int *fd);


int parser(char *file_name, t_data *data)
{
    int     fd;
    int     status;
    
    status = PARSE_ERR;
    if (valid_map_file(file_name, &fd) == SUCCESS)
    {
        status = elements_finder(fd, data, 0);
            // status = save_map(fd, data);
    }
    close(fd);

    //check
    if (status == SUCCESS)
        print_parsing(data);
    
    clean_parse(data);
    return (status);
}


//save the map to an array
//make sure that there isn't invalid text under the map
//check that the map is valid:
//trim \n
//trim the array to the first accurance of '1'
int    save_map(int fd, t_data *data, char **line, int *found_map)
{
    int length;
    char **map;
    
    if (*found_map)
        return (err_msg("Invalid map :/", PARSE_ERR));
    length = 1;
    map = (char **) malloc (sizeof(char *) * (2));
    map[0] = ft_strdup(*line);
    map[1] = NULL;
    while (*line != NULL)
    {
        free(*line);
        *line = get_next_line2(fd);
        if (!*line)
            break;
        if (!is_first_occurance(*line, '1'))
        {
            if (!line_empty(*line))
                return (err_msg("Invalid map :/", PARSE_ERR));
            break ;
        }
        map = add_line_to_arr(map, *line, &length);
    }
    data->map = map;
    *found_map = 1;
    return (SUCCESS);
}

//adds a new line to the map array
char     **add_line_to_arr(char **map, char *line, int *length)
{
    char    **tmp;
    int     i;

    tmp = (char **) malloc (sizeof(char *) * (*length + 2));
    i = 0;
    while (i < *length)
    {
        tmp[i] = ft_strdup(map[i]);
        free(map[i]);
        i++;
    }
    tmp[i] = ft_strdup(line);
    tmp[i+1] = NULL;
    *length = *length + 1;
    free(map);
    return (tmp);
}


int    elements_finder(int fd, t_data *data, int status)
{
    char    *line;
    int     found_map;
    
    line = NULL;
    found_map = 0;
    status = SUCCESS;
    while (status != PARSE_ERR)
    {
        if (line)
            free(line);
        // printf("line start: %s", line);
        line = get_next_line2(fd);
        // printf("line: %s\n", line);
        if (!line && found_map)
            return (status); //found map = 1
        if (!line)
            return (err_msg("No map found in file :/", PARSE_ERR)); //found map = 0
        if (line_empty(line))
            continue ;
        if (is_first_occurance(line, '1') != NULL)
            status = save_map(fd, data, &line, &found_map);
        else
            status = parse_elements(line, data, found_map);
    }
    free(line);
    return (status);
}


//check for no spaces in file's name, for .cub format and if file exists
static int valid_map_file(char *name, int *fd)
{
    int i;

    if (name[0] == '\0')
        return (err_msg("Empty file name :/", PARSE_ERR));
    i = 0;
    while (name[i] != '\0' && name[i] != '.')
    {
        if (name[0] == ' ')
            return (err_msg("No spaces in the filename please :/", PARSE_ERR));
        i++;
    }
    if (ft_strcmp(&name[i], ".cub") != 0)
        return (err_msg("Wrong file format. Should be of format \".cub\" :/", PARSE_ERR));
    *fd = open(name, O_DIRECTORY);
    if (*fd != -1)
        return (err_msg("File is a directory :/", PARSE_ERR));
    *fd = open(name, O_RDONLY);
    if (*fd == -1)
        return (err_msg("File has no permissions or doesn't exists :/", FAILURE));
    return (SUCCESS);
}

