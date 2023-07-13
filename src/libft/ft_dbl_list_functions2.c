/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dbl_list_functions2.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 11:55:39 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/13 08:26:09 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_dbl	*ft_lstlast_dbl(t_list_dbl *lst)
{
	if (lst == (NULL))
		return (NULL);
	while (lst->next != (NULL))
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstiter_dbl(t_list_dbl *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst != (NULL))
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

void	ft_lstclear_dbl(t_list_dbl **lst, void (*del)(void *))
{
	t_list_dbl	*temp;
	t_list_dbl	*temp2;

	if (lst && *lst)
	{
		temp = *lst;
		while (temp != NULL)
		{
			temp2 = temp;
			temp = temp->next;
			del(temp2->content);
			free(temp2);
		}
		*lst = (NULL);
	}
}
