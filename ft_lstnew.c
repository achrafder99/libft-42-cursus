/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:15:04 by adardour          #+#    #+#             */
/*   Updated: 2022/10/24 16:14:10 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_tlist;

	new_tlist = NULL;
	new_tlist = (t_list *)malloc(sizeof(t_list));
	if (new_tlist == NULL)
		return (NULL);
	new_tlist->content = content;
	new_tlist->next = NULL;
	return (new_tlist);
}
