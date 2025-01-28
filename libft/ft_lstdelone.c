/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:27:08 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:17:12 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function deletes a single node from a linked list. It takes a pointer 
to the node to be deleted ('lst') and a function pointer ('del') as parameters. 
The 'del' function is used to free the memory allocated for the content of the 
node. After freeing the content, it frees the node itself.*/

#include "libft_pf_gnl.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
