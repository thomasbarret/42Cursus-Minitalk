/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:21:54 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/14 15:24:06 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*b;
	size_t	m;

	m = nmemb * size;
	if ((int)m < 0 || ((int)size < 0 && (int)nmemb < 0))
		return (0);
	b = malloc(m);
	if (!b)
		return (0);
	ft_bzero(b, m);
	return (b);
}
