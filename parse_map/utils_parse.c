/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:31:50 by ilazar            #+#    #+#             */
/*   Updated: 2025/02/01 17:09:30 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parse.h"


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


//returns 1 if line contains only spaces and tabs
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
    // printf("empty: %s", line);
    return (1);
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
