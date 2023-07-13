/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_char_str_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 10:41:42 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/12 13:15:32 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s && fd >= 0)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
