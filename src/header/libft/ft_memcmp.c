/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:56:28 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/10 13:45:52 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	*k;

	i = 0;
	j = (unsigned char *)s1;
	k = (unsigned char *)s2;
	if (!n)
		return (0);
	while (j[i] == k[i] && i < n - 1)
		i++;
	return (j[i] - k[i]);
}
