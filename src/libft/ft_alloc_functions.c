/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_alloc_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:51:08 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/12 13:21:18 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*str;
	size_t		i;

	i = 0;
	str = malloc(count * size);
	if (str == (NULL))
		return (NULL);
	while (i < count * size)
	{
		*((char *)str + i) = '\0';
		i++;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == (NULL))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	size_t	i;

	i = 0;
	if (s == (NULL))
		return (NULL);
	s1 = (char *)malloc(ft_strlen(s) + 1);
	if (s1 == (NULL))
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(s1 + i) = f(i, *(s + i));
		i++;
	}
	*(s1 + i) = '\0';
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (s1 == (NULL) || set == (NULL))
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		j = 0;
	while (*(s1 + i) != '\0')
	{
		if (ft_strchr(set, *(s1 + i)) == (NULL))
			break ;
		i++;
	}
	while (j > 0)
	{
		if (ft_strrchr(set, *(s1 + j)) == (NULL))
			break ;
		j--;
	}
	s = ft_substr(s1, i, j - i + 1);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (s == (NULL))
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(s) - start)
		substr = (char *)malloc(len + 1);
	else
		substr = (char *)malloc(ft_strlen(s) - start + 1);
	if (substr == (NULL))
		return (NULL);
	while (i < len && i < ft_strlen(s) - start)
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}
