/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:18 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:17:41 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pf_gnl.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}

/* int	main(void)
{
	size_t	i = 0;
	char	*mystring = "3 body problem";

	while (mystring[i])
	{
		printf("%d", ft_isalpha(mystring[i]));
		i++;
	}
	return (0);
} */
