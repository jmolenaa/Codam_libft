/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 10:15:42 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/12 13:34:50 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (ptr == (NULL))
		return (NULL);
	ptr->content = content;
	ptr->next = (NULL);
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (new_node != (NULL) && lst != (NULL))
	{
		if (*lst != (NULL))
		{
			temp = *lst;
			while (temp->next != (NULL))
				temp = temp->next;
			temp->next = new_node;
		}
		else
			*lst = new_node;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (new_node || lst || *lst)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

int	ft_lstsize(t_list *lst)
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
