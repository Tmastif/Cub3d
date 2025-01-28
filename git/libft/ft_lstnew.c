/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:16 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:17:03 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates memory for a new node in a linked list. It initia-
lizes the 'content' member of the node with the value passed as the 'content' 
parameter. The 'next' member is set to NULL, indicating that this node is cur-
rently the last node in the list.*/

#include "libft_pf_gnl.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
