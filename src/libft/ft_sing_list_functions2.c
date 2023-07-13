/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sing_list_functions2.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 11:55:39 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/13 08:32:00 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == (NULL))
		return (NULL);
	while (lst->next != (NULL))
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

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

static t_list	*recur(t_list *l, void *(*f)(void *), \
void (*d)(void *), t_list *n)
{
	t_list	*temp;
	t_list	*check;

	if (l->next != (NULL))
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			return (NULL);
		n->next = temp;
		n->content = f(l->content);
		l = l->next;
		check = recur(l, f, d, temp);
		if (!check)
		{
			d(n->content);
			free(temp);
			return (NULL);
		}
	}
	else
	{
		n->next = (NULL);
		n->content = f(l->content);
	}
	return (n);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*check;

	if (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (NULL);
		check = recur(lst, f, del, new);
		if (!check)
		{
			free(new);
			return (NULL);
		}
		return (new);
	}
	return (NULL);
}
