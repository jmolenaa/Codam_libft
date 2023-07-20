/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_join_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 14:07:51 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/20 13:22:56 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 == (NULL) || s2 == (NULL))
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == (NULL))
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (s3);
}

char	*ft_strjoin_free_first(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 == (NULL) || s2 == (NULL))
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == (NULL))
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free((char *)s1);
	return (s3);
}

char	*ft_strjoin_free_second(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 == (NULL) || s2 == (NULL))
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == (NULL))
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free((char *)s2);
	return (s3);
}

char	*ft_strjoin_free_both(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 == (NULL) || s2 == (NULL))
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == (NULL))
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free((char *)s1);
	free((char *)s2);
	return (s3);
}
