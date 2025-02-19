/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:01:22 by inbar             #+#    #+#             */
/*   Updated: 2025/02/19 12:49:26 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_min_start(t_data *data, int *min_start, int i);

int	trim_lines(t_data *data)
{
	int		status;

	status = trim_leftend(data);
	if (status == SUCCESS)
		status = trim_rightend(data);
	return (status);
}

//trims all spaces from the left and right sides of the map, trims \n
//saves map height
//may return malloc err or parse err
int	trim_leftend(t_data *data)
{
	int		min_start;
	int		len;
	int		i;
	char	*tmp;

	min_start = 0;
	if (get_min_start(data, &min_start, 0) == PARSE_ERR)
		return (PARSE_ERR);
	i = -1;
	while (data->input.map[++i] != NULL)
	{
		len = ft_strlen(data->input.map[i]) - 1;
		tmp = ft_substr(data->input.map[i], min_start, len - min_start);
		if (tmp == NULL)
			return (MALLOC_ERR);
		free(data->input.map[i]);
		data->input.map[i] = ft_strdup(tmp);
		if (data->input.map[i] == NULL)
			return (MALLOC_ERR);
		free(tmp);
	}
	data->input.h_map = i;
	return (SUCCESS);
}

//find the leftmost start of the lines in the map array
static int	get_min_start(t_data *data, int *min_start, int i)
{
	int		start;
	char	*line_start;

	line_start = is_first_occurance(data->input.map[0], '1');
	if (line_start == NULL)
		return (PARSE_ERR);
	*min_start = line_start - data->input.map[0];
	i = 0;
	while (data->input.map[++i] != NULL)
	{
		line_start = is_first_occurance(data->input.map[i], '1');
		if (line_start == NULL)
			return (PARSE_ERR);
		start = line_start - data->input.map[i];
		if (start < *min_start)
			*min_start = start;
	}
	return (SUCCESS);
}

//extracts player position and direction, returns error if found invalid char
//bc of extracting player's position, should happen after trimming map lines
int	valid_chars(t_data *data, int i, int j)
{
	char	c;

	i = 1;
	while (data->input.map[++i] != NULL)
	{
		j = -1;
		while (data->input.map[i][++j] != '\0')
		{
			c = data->input.map[i][j];
			if (is_player(c))
			{
				if (data->input.play_x != -1)
					return (err_msg("Multiple players in map :/", PARSE_ERR));
				data->input.play_x = j;
				data->input.play_y = i;
				data->input.cardinal = c;
				continue ;
			}
			if (c != ' ' && c != '1' && c != '0')
				return (err_msg("Forbbiden character in map:/", PARSE_ERR));
		}
	}
	if (data->input.play_x != -1)
		return (SUCCESS);
	return (err_msg("No player found in map :/", PARSE_ERR));
}

//returns 1 if char is a player char
int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
