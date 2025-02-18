/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:01 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:17:15 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function deletes and frees all nodes in a linked list. It takes the ad-
dress of a pointer to the first link of the list ('lst') and a function pointer
('del') as parameters. It iterates through the list, deleting each node one by
one using ft_lstdelone, and finally sets the pointer to the list to NULL.*/

#include "libft_pf_gnl.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
