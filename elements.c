/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:02:11 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/01 17:35:00 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d_parse.h"

static int      get_elem_path(char *line, char **element);
static int      get_clr_elem(char *line, int *element);
static int      get_clr_component(char *line, int *i, int *comp);


//**need to add possibility to read and ignore spaces from end of string */


//when an element is found it will be validated and stored in data.
//if element is invalid returns failure
int     parse_elements(char *line, t_data *data, int found_map)
{
    int     status;
    int     i;
    
    if (found_map)
        return(err_msg("The map isn't the last element in the file :/", FAILURE));
    status = FAILURE;
    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;

    if (line[i] == 'N' && line[i + 1] == 'O')
        status = get_elem_path(line, &data->no);
    else if (line[i] == 'S' && line[i + 1] == 'O')
        status = get_elem_path(line, &data->so);
    else if (line[i] == 'W' && line[i + 1] == 'E')
        status = get_elem_path(line, &data->we);
    else if (line[i] == 'E' && line[i + 1] == 'A')
        status = get_elem_path(line, &data->ea);
    else if (line[i] == 'F')
        status = get_clr_elem(&line[i + 1], &data->floor_clr);
    else if (line[i] == 'C')
        status = get_clr_elem(&line[i + 1], &data->ceiling_clr);
    return(status);
}

//saves paths for NO SU WE EA
//doesn't check if path exists - will be checked before loading the texture
static int     get_elem_path(char *line, char **element)
{
    int start;
    int end;

    if (*element)
        return (err_msg("Map contains a duplicate element :/", PARSE_ERR));
    start = 2;
    while (line[start] == ' ')
        start++;
    end = start;
    while (line[end] != '\n' && line[end] != '\0')
    {
        if (!ft_isascii(line[end]) || ft_isspace(line[end]))
           return (err_msg("Map contains a bad path :/", PARSE_ERR));
        end++;
    }
    if (end == start)
        return (err_msg("Map is missing a path :/", PARSE_ERR));
    line[end] = '\0';
    *element = ft_strdup(&line[start]);
    if (*element == NULL)
        return (MALLOC_ERR);
    return (SUCCESS);
}

//saves Floor or Ceiling color elements
static int get_clr_elem(char *line, int *element)
{
    int i;
    int r;
    int g;
    int b;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (get_clr_component(line, &i, &r) == -1)
        return (PARSE_ERR);
    // printf("rgb: %d,", r);
    if (get_clr_component(line, &i, &g) == -1)
        return (PARSE_ERR);
    // printf("%d,", g);
    if (get_clr_component(line, &i, &b) == -1)
        return (PARSE_ERR);
    // printf("%d\n", b);
    while (line[i] == ' ')
        i++;
    if (line[i] != '\n' && line[i] != '\0')
        return (err_msg("Map contains a bad color element :/", PARSE_ERR));
    *element = r << 16 | g << 8 | b;
    return (SUCCESS);
}

//gets the R G or B component or a color
static int     get_clr_component(char *line, int *i, int *comp)
{
    *comp = 0;
    if (line[*i] == '\0' || !ft_isdigit(line[*i]) )
        return (err_msg("Map contains a bad color element :/", -1));
    while (line[*i] != '\0' && line[*i] != ',')
    {
        if (line[*i] == '\n' || line[*i] == ' ')
            break ;
        if (!ft_isdigit(line[*i]))
            return (err_msg("Map contains an impossible color :/", -1));
        *comp = *comp + line[*i] - '0';
        *i = *i + 1;
        if (ft_isdigit(line[*i]))
		    *comp = *comp * 10;
    }
    *i = *i + 1;
    if (*comp > 255 || *comp < 0)
            return (err_msg("Map contains an impossible color :/", -1));
    return (*comp);
}

