/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:11:28 by ilazar            #+#    #+#             */
/*   Updated: 2025/01/28 17:39:41 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//map validation

#include "cub2d.h"
#include "get_next_line_bonus.h"
#include "gnl.h"

static int valid_map_file(char *name, int *fd);

int     elements_finder(int fd, t_data *data, int status);
int     get_map(int fd, t_data *data);
void    line_to_arr(char **map, char *line);
void	free_2d_char(char **arr);
void    clean_parse(t_data *data);

int make_map(char *file_name, t_data *data)
{
    int     fd;
    int     status;
    
    status = FAILURE;
    if (valid_map_file(file_name, &fd) == SUCCESS)
    {
        if (elements_finder(fd, data, 0) == SUCCESS)
            status = get_map(fd, data);
    }
    close(fd);


    //check
    printf("CHECK:\n");
    printf("No: %s\n", data->no);
    printf("So: %s\n", data->so);
    printf("Wo: %s\n", data->we);
    printf("Eo: %s\n", data->ea);

    printf("F: %d\n", data->floor_clr);
    printf("C: %d\n", data->ceiling_clr);


    clean_parse(data);
    return (status);
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

int    get_map(int fd, t_data *data)
{
    //free line
    (void) fd;
    (void) data;
    
    char    *line;
    
    line = NULL;

    return (SUCCESS);
}

int     get_elem_path(char *line, char **element)
{
    int i;

    if (*element)
        return (FAILURE);
    i = 2;
    while (line[i] == ' ')
        i++;
    if (line[i] == '\0')
        return (err_msg("bad path :/", FAILURE));
    *element = ft_strdup(&line[i]);
    return (SUCCESS);
}

int get_clr_elem(char *line, int *element)
{
    int r;
    int g;
    int b;


    (void) line;
    r = 225;
    g = 12;
    b = 0;
    *element = r << 16 | g << 8 | b;
    return (SUCCESS);
    //else return FAILURE
}

//an element found - will be validated and stored in data. if not valid returns NULL
int     parse_elements(char *line, int i, t_data *data)
{
    int     status;
    
    status = FAILURE;
    if (line[i] == 'N' && line[i + 1] == 'O')
        status = get_elem_path(line, &data->no);
    if (line[i] == 'S' && line[i + 1] == 'O')
        status = get_elem_path(line, &data->so);
    if (line[i] == 'W' && line[i + 1] == 'E')
        status = get_elem_path(line, &data->we);
    if (line[i] == 'E' && line[i + 1] == 'A')
        status = get_elem_path(line, &data->ea);
    if (line[i] == 'F')
        status = get_clr_elem(line, &data->floor_clr);
    if (line[i] == 'C')
        status = get_clr_elem(line, &data->ceiling_clr);
    return(status);
}


int    elements_finder(int fd, t_data *data, int status)
{
    char    *line;
    int     i;
    
    line = NULL;
    while (1 && status != FAILURE)
    {
        if (line)
            free(line);
        line = get_next_line2(fd);
        if (!line)
            return (err_msg("No map found in file :/", FAILURE));
        printf("%s", line);
        i = 0;
        while (line[i] == ' ')
            i++;
        if (line[i] == '\n')
            continue ;
        if (line[i] == '1')
        {
            // line_to_arr(data->map, &line[i]);
            break ;
        }
        status = parse_elements(line, i, data);
    }
    free(line);
    return (status);
}

void line_to_arr(char **map, char *line)
{
    (void)map;
    (void)line;
    // map[0] = ft_strdup(line);
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
void	free_2d_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}