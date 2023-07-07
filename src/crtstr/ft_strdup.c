/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 19:10:59 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/07 10:34:07 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if (s2 == (NULL))
		return (NULL);
	while (i < len)
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
