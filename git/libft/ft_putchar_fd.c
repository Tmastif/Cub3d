/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:36:49 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:16:39 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*c: The character to output. fd: The file descriptor on which to write.
External functs. write
Outputs the character ’c’ to the given file descriptor.*/

#include "libft_pf_gnl.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(void)
{
	ft_putchar_fd('k', 2);
	return (0);
} */
