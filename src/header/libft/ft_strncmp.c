/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:49:17 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/10 13:59:14 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	*k;

	i = 0;
	j = (unsigned char *)s1;
	k = (unsigned char *)s2;
	if (!n)
		return (0);
	while (j[i] && j[i] == k[i] && i < n - 1)
		i++;
	return (j[i] - k[i]);
}
