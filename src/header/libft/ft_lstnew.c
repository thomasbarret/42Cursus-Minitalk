/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:27:24 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/15 18:28:59 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r;

	r = (t_list *)malloc(sizeof(*r));
	if (!r)
		return (0);
	r->content = content;
	r->next = NULL;
	return (r);
}
