/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:26 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:17:35 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pf_gnl.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	return (1);
}

/* int	main(void)
{
	size_t	i = 0;
	char	*mystring = "3 body \nproblem ©";

	while (mystring[i])
	{
		printf("%d", ft_isascii(mystring[i]));
		i++;
	}
	return (0);
} */
