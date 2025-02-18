/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:32:28 by ilazar            #+#    #+#             */
/*   Updated: 2025/01/28 17:11:23 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_bytes(int fd, char *buffer, char *stash);
static char	*trim_line_left(char *stash, char *br_indx);
static char	*trim_line_right(char *stash, char *br_indx);
static char	*join_free(char *stash, char *buffer);


//check for value higher than MAX_FD
char	*get_next_line1(int fd)
{
	char		*new_line;
	static char	*stash[MAX_FD];
	char		*buffer;
	char		*br_indx;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) > 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	if (!stash[fd] || (stash[fd] && !ft_strchr(stash[fd], '\n')))
		stash[fd] = read_bytes(fd, buffer, stash[fd]);
	free(buffer);
	if (stash[fd] == NULL)
		return (NULL);
	br_indx = ft_strchr(stash[fd], '\n');
	new_line = trim_line_right(stash[fd], br_indx);
	stash[fd] = trim_line_left(stash[fd], br_indx);
	return (new_line);
}

static char	*read_bytes(int fd, char *buffer, char *stash)
{
	int	bytes_read;

	bytes_read = 1;
	if (ft_strchr(stash, '\n'))
		return (stash);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			return (stash);
		buffer[bytes_read] = '\0';
		stash = join_free(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			return (stash);
	}
	return (stash);
}

static char	*join_free(char *stash, char *buffer)
{
	char	*tmp;

	tmp = stash;
	stash = ft_strjoin(tmp, buffer);
	free(tmp);
	return (stash);
}

static char	*trim_line_right(char *stash, char *br_indx)
{
	int		length;
	char	*new_line;

	if (stash[0] == '\0')
		return (NULL);
	if (br_indx == NULL)
		return (ft_strdup(stash));
	length = br_indx - stash + 1;
	new_line = ft_substr(stash, 0, length);
	if (!new_line)
		return (NULL);
	return (new_line);
}

static char	*trim_line_left(char *stash, char *br_indx)
{
	int		length;
	int		start_indx;
	int		stash_len;
	char	*new_stash;

	if (br_indx == NULL)
	{
		free(stash);
		return (NULL);
	}
	stash_len = ft_strlen(stash);
	start_indx = br_indx - stash + 1;
	length = stash_len - start_indx + 1;
	new_stash = ft_substr(stash, start_indx, length);
	free(stash);
	return (new_stash);
}

/*
int	main(void)
{
	int		fd[4];
	char	*next_line[3];

	int x;
	x = 0;

	fd[0] = open("file0.txt", O_RDONLY);
	fd[1] = open("file1.txt", O_RDONLY);
	fd[2] = open("file2.txt", O_RDONLY);
	fd[3] = open("file3.txt", O_RDONLY);

	while (1)
	{
		next_line[x] = get_next_line(fd[x]);
		if (next_line[x] == NULL)
		{
			free(next_line[x]);
			break ;
		}
		printf("**************\n");
		printf("fd%d: %s", x, next_line[x]);
		printf("**************\n");
		free(next_line[x]);
		x++;
		if (x > 3)
			x = 0;
	}
	x = 0;
	while (x <= 3)
	{
		close(fd[x]);
		x++;
	}
	return (0);
}
*/
