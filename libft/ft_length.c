/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:17:19 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:20:06 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pf_gnl.h"

size_t	ft_intlen(int n, int base)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

size_t	ft_uintlen(unsigned int n, int base)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

size_t	ft_ulonglen(unsigned long n, int base)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}
