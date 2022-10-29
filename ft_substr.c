/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:25:48 by adardour          #+#    #+#             */
/*   Updated: 2022/10/29 13:01:22 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	buffer = ft_strdup(s);
	if (buffer == NULL)
		return (NULL);
	if (len > ft_strlen(buffer))
		len = ft_strlen(buffer);
	if (start >= (unsigned long)ft_strlen(buffer))
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (substr == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		substr[i] = buffer[start];
		i++;
		start++;
	}
	substr[len] = '\0';
	return (substr);
}
