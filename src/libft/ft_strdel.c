/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 13:23:33 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/12/07 13:28:17 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_to_be_deleted(char *str, char *del)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		while (del[j])
		{
			if (str[i] == del[j])
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	in_del(char c, char *del)
{
	int	i;

	i = 0;
	while (del[i])
	{
		if (del[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*Deletes any occurance of any character in "del" out of the input string "str"
the result is malloced and (*WARNING*) the original string is freed*/
char	*ft_strdel(char *str, char *del)
{
	size_t	len;
	char	*ret;
	int		i;
	int		j;

	len = ft_strlen(str) - char_to_be_deleted(str, del);
	if (len == ft_strlen(str))
		return (str);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (in_del(str[i], del) == 0)
		{
			ret[j] = str[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	free (str);
	return (ret);
}
