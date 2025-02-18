/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:37:26 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:16:36 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*s: The string to output.fd: The file descriptor on which to write.
External functs. write. Outputs the string ’s’ to the given file descriptor
followed by a newline.*/

#include "libft_pf_gnl.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd);
		i++;
	}
	write(fd, "\n", 1);
}

/* int	main(void)
{
	ft_putendl_fd("Luxe, calme et volupte.", 1);
	return (0);
} */
