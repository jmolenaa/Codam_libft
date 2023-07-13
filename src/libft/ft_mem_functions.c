/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 09:33:19 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/12 13:30:51 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (dst > src)
			*((char *)dst + len - i - 1) = *((char *)src + len - i - 1);
		else if (dst < src)
			*((char *)dst + i) = *((char *)src + i);
		else
			return (dst);
		i++;
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		*((char *) dst + i) = *((char *) src + i);
		i++;
	}
	return (dst);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;
	char	*s1t;
	char	*s2t;

	i = 0;
	diff = 0;
	s1t = (char *)s1;
	s2t = (char *)s2;
	while (diff == 0 && i < n)
	{
		diff = (unsigned char) *(s1t + i) - (unsigned char) *(s2t + i);
		i++;
	}
	return (diff);
}
