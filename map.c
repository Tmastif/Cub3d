/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:11:28 by ilazar            #+#    #+#             */
/*   Updated: 2025/01/31 16:41:56 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//map validation

#include "cub3d_parse.h"
#include "get_next_line_bonus.h"
#include "gnl.h"


int     elements_finder(int fd, t_data *data, int status);
int    save_map(int fd, char ***map, char **line, int *found_map);
void    clean_parse(t_data *data);

char     **add_line_to_arr(char **map, char *line, int *length);


static int valid_map_file(char *name, int *fd);

int make_map(char *file_name, t_data *data)
{
    int     fd;
    int     status;
    
    status = FAILURE;
    if (valid_map_file(file_name, &fd) == SUCCESS)
    {
        status = elements_finder(fd, data, 0);
            // status = save_map(fd, data);
    }
    close(fd);

    //check
    if (status == SUCCESS)
    {
        printf("\nCHECK:\n");
        printf("No: $%s$\n", data->no);
        printf("So: $%s$\n", data->so);
        printf("Wo: $%s$\n", data->we);
        printf("Eo: $%s$\n", data->ea);

        printf("F: %d\n", data->floor_clr);
        printf("C: %d\n", data->ceiling_clr);

        // print_map(data->map);

    }
    
    printf("No: $%s$\n", data->no);
    clean_parse(data);
    return (status);
}


//save the map to an array
//make sure that there isn't invalid text under the map
//check that the map is valid:
//trim \n
//trim the array to the first accurance of '1'
int    save_map(int fd, char ***map, char **line, int *found_map)
{
    int length;
    
    if (*found_map)
        return (err_msg("Invalid map :/", FAILURE));
    length = 1;
    *map = (char **) malloc (sizeof(char *) * (2));
    *map[0] = ft_strdup(*line);
    *map[1] = NULL;
    while (*line != NULL)
    {
        free(*line);
        *line = get_next_line2(fd);
        if (!*line)
            break;
        if (!is_first_occurance(*line, '1'))
        {
            if (!line_empty(*line))
                return (err_msg("Invalid map2 :/", FAILURE));
            else
                break ;
        }
        *map = add_line_to_arr(*map, *line, &length);
    }
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
    while (status != FAILURE)
    {
        if (line)
            free(line);
        // printf("line start: %s", line);
        line = get_next_line2(fd);
        // printf("line: %s\n", line);
        if (!line && found_map)
        {
            printf("Nooooo: $%s$\n", data->no);
            printf("Sooooo: $%s$\n", data->so);
            return (status); //found map = 1
        }
        if (!line)
            return (err_msg("No map found in file :/", FAILURE)); //found map = 0
        if (line_empty(line))
            continue ;
        if (is_first_occurance(line, '1') != NULL)
            status = save_map(fd ,&data->map, &line, &found_map);
        else
            status = parse_elements(line, data, found_map);
        // printf("line end: %s\n", line);
    }
    // if (line)
    
    free(line);
    printf("Nooooo: $%s$\n", data->no);
    return (status);
}


//check for no spaces in file's name, for .cub format and if file exists
static int valid_map_file(char *name, int *fd)
{
    int i;

    if (name[0] == '\0')
        return (err_msg("Empty file name :/", FAILURE));
    i = 0;
    while (name[i] != '\0' && name[i] != '.')
    {
        if (name[0] == ' ')
            return (err_msg("No spaces in the filename please :/", FAILURE));
        i++;
    }
    if (ft_strcmp(&name[i], ".cub") != 0)
        return (err_msg("Wrong file format. Should be of format \".cub\" :/", FAILURE));
    *fd = open(name, O_DIRECTORY);
    if (*fd != -1)
        return (err_msg("File is a directory :/", FAILURE));
    *fd = open(name, O_RDONLY);
    if (*fd == -1)
        return (err_msg("File has no permissions or doesn't exists :/", FAILURE));
    return (SUCCESS);
}

void    clean_parse(t_data *data)
{
    if (data->map)
        free_2d_char(data->map);
    if (data->no)
        free(data->no);
    if (data->so)
        free(data->so);
    if (data->we)
        free(data->we);
    if (data->ea)
        free(data->ea);
}
