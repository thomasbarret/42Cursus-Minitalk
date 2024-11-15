/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:45:56 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/10 14:49:04 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	d = (char *)malloc(sizeof(*s1) * i + 1);
	if (!d)
		return (NULL);
	while (j < i)
	{
		d[j] = s1[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}
