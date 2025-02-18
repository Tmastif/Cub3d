/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:10 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:17:08 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function returns a pointer to the last node in a linked list. It takes 
the beginning of the list ('lst') as a parameter and iterates through the list 
until reaching the last node. It then returns a pointer to this last node.*/

#include "libft_pf_gnl.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
