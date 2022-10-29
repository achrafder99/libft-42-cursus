/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:48:52 by adardour          #+#    #+#             */
/*   Updated: 2022/10/18 11:00:58 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*currentnode;

	i = 0;
	currentnode = lst;
	while (currentnode != NULL)
	{
		++i;
		currentnode = currentnode->next;
	}
	return (i);
}
