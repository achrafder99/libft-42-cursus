/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:18:35 by adardour          #+#    #+#             */
/*   Updated: 2022/10/25 13:57:49 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*_(unsigned char *dst1, unsigned char *src1, size_t end)
{
	size_t	i;

	i = 0;
	dst1 = dst1 + end;
	src1 = src1 + end;
	while (i <= end)
	{
		*dst1 = *src1;
		dst1--;
		src1--;
		i++;
	}
	return (dst1);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;
	size_t			end;

	dst1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	end = len - 1;
	i = 0;
	if (dst1 == src1 || len == 0)
		return (dst1);
	if (src > dest)
	{
		while (i <= end)
		{
			*dst1 = *src1;
			dst1++;
			src1++;
			i++;
		}
	}
	else
		_(dst1, src1, end);
	return (dest);
}
