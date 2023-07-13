/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_safe_alloc_and_free_null.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 14:03:17 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/13 07:50:04 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <errno.h>

void	*safe_malloc(size_t size, char *msg)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror(msg);
		exit(errno);
	}
	return (ptr);
}

void	*safe_calloc(size_t size, char *msg)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (ptr == NULL)
	{
		perror(msg);
		exit(errno);
	}
	return (ptr);
}

void	free_and_set_null(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
