/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:31:47 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/10 14:56:16 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (h == n || !n[0])
		return ((char *)h);
	while (i < len && h[i])
	{
		x = 0;
		while (h[i + x] && h[i + x] == n[x]
			&& i + x < len)
		{
			if (!n[x + 1])
				return ((char *)&h[i]);
			++x;
		}
		++i;
	}
	return (0);
}
