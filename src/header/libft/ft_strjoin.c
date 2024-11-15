/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:10:12 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/14 00:14:32 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *r, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		r[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		r[j] = s2[i];
		i++;
		j++;
	}
	r[j] = '\0';
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*r;

	if (!s1 || !s2)
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2);
	r = (char *)malloc(sizeof(char) * l + 1);
	if (!r)
		return (0);
	r = ft_join(r, s1, s2);
	return (r);
}
