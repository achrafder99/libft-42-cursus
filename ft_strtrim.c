/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:58:03 by adardour          #+#    #+#             */
/*   Updated: 2022/10/29 18:30:19 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getindex(char *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (ft_strchr(set, str[i + 1]) == NULL)
			break ;
		i++;
	}
	if (i > 0)
		return (i += 1);
	return (i);
}

static int	getlastindex(char *str, char const *set)
{
	int	end;
	int	j;

	end = ft_strlen(str);
	while (end > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[end] == set[j])
			{
				break ;
			}
			j++;
		}
		if (ft_strchr(set, str[end - 1]) == NULL)
		{
			break ;
		}
		end--;
	}
	return (end);
}

static char	*allocate(char *const str, size_t start, size_t end)
{
	char	*substr;
	size_t	size;

	size = ((ft_strlen(str)) - ((ft_strlen(str) - end) + start));
	if (start - 1 == ft_strlen(str) && end == 0)
	{
		substr = (char *)malloc((sizeof(char) * 0) + 1);
		substr[size] = '\0';
		return (substr);
	}
	substr = (char *)malloc((sizeof(char) * size) + 1);
	if (substr == NULL)
		return (NULL);
	substr = ft_memcpy(substr, str + start, size);
	substr[size] = '\0';
	return (substr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = ft_strdup(s1);
	if (str == NULL)
		return (NULL);
	start = getindex(str, set);
	end = getlastindex(str, set);
	return (allocate(str, start, end));
}
