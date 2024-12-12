/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:25:54 by akloster          #+#    #+#             */
/*   Updated: 2023/11/08 13:18:42 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*make_map(t_list *lst, void *(*f)(void *), void (*del)(void *),
t_list *head)
{
	void	*data;
	t_list	*node;

	while (lst != NULL)
	{
		data = f(lst->content);
		if (!data && lst->content)
			return (ft_lstclear(&head, del), del(data), NULL);
		node = ft_lstnew(data);
		if (!node)
			return (ft_lstclear(&head, del), del(data), NULL);
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	data = f(lst->content);
	if (lst->content && !data)
		return (NULL);
	node = ft_lstnew(data);
	if (!node)
		return (del(data), NULL);
	head = node;
	lst = lst->next;
	return (make_map(lst, f, del, head));
}
