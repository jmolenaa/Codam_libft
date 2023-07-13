/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cir_list_functions1.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 10:15:42 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/13 08:24:23 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_dbl	*ft_lstnew_dbl(void *content)
{
	t_list_dbl	*ptr;

	ptr = (t_list_dbl *)malloc(sizeof(t_list_dbl));
	if (ptr == (NULL))
		return (NULL);
	ptr->content = content;
	ptr->next = (NULL);
	ptr->prev = (NULL);
	return (ptr);
}

void	ft_lstadd_back_dbl(t_list_dbl **lst, t_list_dbl *new_node)
{
	t_list_dbl	*temp;

	if (new_node != (NULL) && lst != (NULL))
	{
		if (*lst != (NULL))
		{
			temp = *lst;
			while (temp->next != (NULL))
				temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
		else
			*lst = new_node;
	}
}

void	ft_lstadd_front_dbl(t_list_dbl **lst, t_list_dbl *new_node)
{
	if (new_node || lst || *lst)
	{
		(*lst)->prev = new_node;
		new_node->next = *lst;
		*lst = new_node;
	}
}

int	ft_lstsize_dbl(t_list_dbl *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst != (NULL))
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}
