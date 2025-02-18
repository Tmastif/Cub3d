/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:44 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:16:53 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The memcpy() function copies n bytes from memory area src to memory area dest.
The memcpy() function returns a pointer to dest. */

#include "libft_pf_gnl.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return ((void *)dest);
}

/* int	main(void)
{
	char	*source = "legrandchlem";
	char	*destin = malloc(20);

	printf("Character found: %c\n", *(char *)ft_memcpy(destin, source, 5));
	free(destin);
	return (0);
} */
