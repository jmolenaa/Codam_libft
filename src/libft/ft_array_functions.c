/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 13:54:16 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/13 08:31:53 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_size_of_array(char **array)
{
	int	i;

	i = 0;
	while (*(array + i) != NULL)
		i++;
	return (i);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (*(array + i) != NULL)
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

char	**ft_arrdup(char **array)
{
	char	**duped_array;
	int		i;

	duped_array = ft_calloc(ft_size_of_array(array) + 1, sizeof(char *));
	if (duped_array == NULL)
		return (NULL);
	i = 0;
	while (*(array + i) != NULL)
	{
		*(duped_array + i) = ft_strdup(*(array + i));
		if (*(duped_array + i) == NULL)
		{
			ft_free_array(duped_array);
			return (NULL);
		}
		i++;
	}
	return (duped_array);
}

size_t	copy_array(char **dst, char **src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != NULL)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	return (i);
}

char	**ft_insert_into_array(char **dst, char **src, size_t i)
{
	char	**new_cmd_array;
	size_t	j;

	new_cmd_array = ft_calloc(ft_size_of_array(src) + \
								ft_size_of_array(dst), sizeof(char *));
	if (new_cmd_array != NULL)
		return (NULL);
	j = 0;
	while (j != i)
	{
		*(new_cmd_array + j) = *(dst + j);
		j++;
	}
	j = j + copy_array(new_cmd_array + j, src); 
	j = j + copy_array(new_cmd_array + j, dst + i + 1);
	free(dst);
	dst = new_cmd_array;
	return (new_cmd_array);
}
