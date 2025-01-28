/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:33 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:17:28 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pf_gnl.h"

int	ft_isprint(int c)
{
	if (!((c >= 32 && c <= 126)))
		return (0);
	return (1);
}

/* int	main(void)
{
	size_t	i = 0;
	char	*mystring = "3 body \nproblem ©";

	while (mystring[i])
	{
		printf("%d", ft_isprint(mystring[i]));
		i++;
	}
	return (0);
} */
