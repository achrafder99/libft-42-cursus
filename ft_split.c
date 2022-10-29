/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:34:32 by adardour          #+#    #+#             */
/*   Updated: 2022/10/29 19:03:31 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getrows(char const *s, char delimiter)
{
	int		i;
	int		count;
	char	*trim;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	trim = ft_strtrim(s, &delimiter);
	if (trim == NULL)
		return (0);
	while (trim[i] != '\0')
	{
		while (*trim != '\0' && trim[i] == delimiter)
			i++;
		while (trim[i] != delimiter && trim[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static int	getcolumn(char const *str, char delimiter, int index)
{
	int	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (str[index] != '\0')
	{
		if (str[index] == delimiter)
			break ;
		index++;
		length++;
	}
	return (length);
}

static void	_(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		free(ptr[i]);
	free(ptr);
}

static void	allocate(char *s, char c, char **split, int words)
{
	t_rowsandcolumns	rowandcolumn;

	if (s == NULL || split == NULL)
		return ;
	rowandcolumn = (t_rowsandcolumns){.i = 0, .j = 0, .nextblock = 0};
	while (words)
	{
		while (s[rowandcolumn.i] == c && s[rowandcolumn.i] != '\0')
			rowandcolumn.i++;
		rowandcolumn.j = 0;
		while (s[rowandcolumn.i] != c && s[rowandcolumn.i] != '\0')
		{
			split[rowandcolumn.nextblock][rowandcolumn.j] = s[rowandcolumn.i];
			if (split[rowandcolumn.nextblock] == NULL)
				_(split);
			rowandcolumn.i++;
			rowandcolumn.j++;
		}
		split[rowandcolumn.nextblock][rowandcolumn.j] = '\0';
		words--;
		rowandcolumn.nextblock++;
	}
}

char	**ft_split(char const *s, char c)
{
	t_rowsandcolumns	rowandcolumn;

	rowandcolumn = (t_rowsandcolumns){.i = 0, .j = 0, .nextblock = 0};
	if (s == NULL)
		return (NULL);
	rowandcolumn.words = getrows(s, c);
	rowandcolumn.ptr = malloc((sizeof(char *) * rowandcolumn.words) + 1);
	if (rowandcolumn.ptr == NULL)
		return (NULL);
	while (rowandcolumn.words-- > 0)
	{
		while (s[rowandcolumn.i] == c && s[rowandcolumn.i] != '\0')
			rowandcolumn.i++;
		while (s[rowandcolumn.i] != c && s[rowandcolumn.i] != '\0')
		{
			rowandcolumn.ptr[rowandcolumn.nextblock] = malloc((sizeof(char)
						* getcolumn((char *)s, (char)c, rowandcolumn.i)) + 1);
			rowandcolumn.i += getcolumn(s, c, rowandcolumn.i);
			rowandcolumn.nextblock++;
		}
		if (rowandcolumn.nextblock == getrows(s, c))
			allocate((char *)s, c, rowandcolumn.ptr, getrows(s, c));
	}
	rowandcolumn.ptr[rowandcolumn.nextblock] = NULL;
	return (rowandcolumn.ptr);
}
