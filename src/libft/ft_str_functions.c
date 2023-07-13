/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:34:09 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/12 13:22:59 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char) c)
			return ((char *) s + i);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) s + i);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	while (i >= 0)
	{
		if (*(s + i) == (char) c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	e;

	if (*(needle) == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len)
	{
		if (*(haystack + i) == '\0')
			break ;
		e = 0;
		while (*(haystack + i + e) == *(needle + e))
		{
			if (i + e == len)
				break ;
			if (*(needle + e + 1) == '\0')
				return ((char *)haystack + i);
			e++;
		}
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (diff == 0 && i < n)
	{
		if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
			return (diff);
		diff = (unsigned char)*(s1 + i) - (unsigned char)*(s2 + i);
		i++;
	}
	return (diff);
}
