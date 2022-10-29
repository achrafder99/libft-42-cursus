/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:52:22 by adardour          #+#    #+#             */
/*   Updated: 2022/10/22 00:09:55 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_strlen;
	size_t	src_strlen;
	size_t	k;
	size_t	i;

	if (dst == NULL && dstsize == 0)
	{
		return (0);
	}
	dst_strlen = ft_strlen(dst);
	src_strlen = ft_strlen(src);
	k = src_strlen;
	i = 0;
	if (dstsize <= dst_strlen)
		return (src_strlen + dstsize);
	else
		k = dst_strlen;
	while ((i < dstsize - dst_strlen - 1) && src[i] != '\0')
	{
		dst[k] = src[i];
		i++;
		k++;
	}
	dst[k] = '\0';
	return (dst_strlen + src_strlen);
}
