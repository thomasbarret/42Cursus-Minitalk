/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:45:30 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/15 23:55:02 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r;
	t_list	*t;

	if (!lst || !f || !del)
		return (0);
	r = 0;
	while (lst)
	{
		t = ft_lstnew(f(lst->content));
		if (!t)
		{
			ft_lstclear(&r, del);
			return (0);
		}
		ft_lstadd_back(&r, t);
		lst = lst->next;
	}
	return (r);
}
