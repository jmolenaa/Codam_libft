/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 16:36:41 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/20 11:30:24 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int		strlenornewline(char *str, int check);
char	*join(char *str, char *buff, int check);
char	*substr(char **strtemp, int strtemplenornewline);
char	*freeing(char **str, char **strtemp);
void	stringcpy(char *dest, char *src, int size);

char	*nextlinenobuffer(int fd, char *str, char **strtemp, char *buff)
{
	int		i;
	int		check;

	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (freeing(&str, strtemp));
		check = strlenornewline(buff, i);
		if (check < i)
		{
			str = join(str, buff, check + 1);
			if (str == (NULL))
				return (freeing(&str, strtemp));
			*strtemp = join(*strtemp, buff + check + 1, i - check - 1);
			if (*strtemp == (NULL))
				return (freeing(&str, strtemp));
			return (str);
		}
		str = join(str, buff, check);
		if (str == (NULL))
			return (freeing(&str, strtemp));
	}
	return (str);
}

char	*nextlinewithbuffer(char **strtemp, char **str)
{
	int	strtemplenornewline;

	strtemplenornewline = strlenornewline(*strtemp, BUFFER_SIZE);
	*str = join(*str, *strtemp, strtemplenornewline + 1);
	if (*str == (NULL))
		return (freeing(str, strtemp));
	if (*(*strtemp + strtemplenornewline) == '\n')
	{
		*strtemp = substr(strtemp, strtemplenornewline + 1);
		if (*strtemp == (NULL))
			freeing(str, strtemp);
		return (NULL);
	}
	else
		freeing(NULL, strtemp);
	return (*str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*strtemp = (NULL);
	char		buff[BUFFER_SIZE];

	if (fd < 0 || fd > FD_SETSIZE)
		return (NULL);
	str = (NULL);
	if (strtemp != (NULL))
	{
		if (nextlinewithbuffer(&strtemp, &str) == (NULL))
			return (str);
	}
	str = nextlinenobuffer(fd, str, &strtemp, buff);
	if (str != (NULL) && *str == '\0')
		return (freeing(&str, &strtemp));
	if ((strtemp != (NULL) && *strtemp == '\0'))
		freeing(NULL, &strtemp);
	return (str);
}
