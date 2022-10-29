/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:24:15 by adardour          #+#    #+#             */
/*   Updated: 2022/10/24 23:39:09 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currentnode;

	currentnode = lst;
	if (currentnode == NULL)
		return (NULL);
	while (currentnode->next != NULL)
		currentnode = currentnode->next;
	return (currentnode);
}
