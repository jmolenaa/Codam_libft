/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 13:26:53 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/20 13:48:49 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_exit_with_error(char *str, int error_code)
{
	write(2, str, ft_strlen(str));
	exit(error_code);
}
