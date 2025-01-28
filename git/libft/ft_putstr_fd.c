/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:37:07 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:16:31 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description Outputs the string ’s’ to the given file descriptor.*/

#include "libft_pf_gnl.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/* int	main(void)
{
	ft_putstr_fd("Luxe, calme et volupte.", 1);
	return (0);
} */
