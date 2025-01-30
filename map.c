/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:11:28 by ilazar            #+#    #+#             */
/*   Updated: 2025/01/30 16:21:22 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//map validation

#include "cub3d_parse.h"
#include "get_next_line_bonus.h"
#include "gnl.h"


int     elements_finder(int fd, t_data *data, int status);
int    save_map(int fd, char **map, char **line, int *found_map);
void    line_to_arr(char **map, char *line);
void	free_2d_char(char **arr);
void    clean_parse(t_data *data);

int     line_empty(char *line);
char    *is_first_occurance(char *str, char c);

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
        printf("CHECK:\n");
        printf("No: $%s$\n", data->no);
        printf("So: $%s$\n", data->so);
        printf("Wo: $%s$\n", data->we);
        printf("Eo: $%s$\n", data->ea);

        printf("F: %d\n", data->floor_clr);
        printf("C: %d\n", data->ceiling_clr);

    }
    clean_parse(data);
    return (status);
}


//save the map to an array
//make sure that there isn't invalid text under the map
//check that the map is valid
//trim the array to the first accurance of '1'
int    save_map(int fd, char **map, char **line, int *found_map)
{
    
    if (found_map)
        return (err_msg("Invalid map :/", FAILURE));
    
    printf ("save map: %s", *line);

    
    (void)map;
    (void)fd;
    (void)line;
    // map[0] = ft_strdup(line);
    return (SUCCESS);
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
        line = get_next_line2(fd);

        printf("line: %s", line);
        
        if (!line && found_map) 
            return (status); //found map = 1
        if (!line)
            return (err_msg("No map found in file :/", FAILURE)); //found map = 0
        
        
        if (line_empty(line))
        {
            printf("empty: %s", line);
            continue ;
        }
        // printf("%s", line);
        // i = 0;
        // while (line[i] == ' ') //ft_isspace
        //     i++;
        // if (line[i] == '\n')
        //     continue ;

        // while (ft_isspace(line[i]))
            // i++; 
        // if (line[i] == '1')
        if (is_first_occurance(line, '1') != NULL)
        {
            printf("hey\n");
            status = save_map(fd ,data->map, &line, &found_map);
        }
        else
        {
            // printf("heyjjj\n");
            status = parse_elements(line, data, found_map);
        }
    }
    free(line);
    return (status);
}

//returns 1 if first occurance of the string is char c
//ignores tabs and spaces
char    *is_first_occurance(char *str, char c)
{
    int     i;

    i = 0;

    while (str[i] == '\t' || str[i] == ' ')
        i++;
    if (str[i] == c)
            return (&str[i]);
    return (NULL);
}

int     line_empty(char *line)
{
    int     i;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        if (ft_isspace(line[i]))
            i++;
        else
            return (0);
    }
    return (1);
    }

void line_to_arr(char **map, char *line)
{
    (void)map;
    printf ("%s", line);
    
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

int ft_isspace(char c)
{
    if ((c <= 13 && c >= 9) || c == ' ')
        return (1);
    return (0);
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
