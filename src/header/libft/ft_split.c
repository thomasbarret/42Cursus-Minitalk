/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:27:23 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/11 22:00:03 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bx: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:27:23 bx tbarret           #+#    #+#             */
/*   Updated: 2023/11/11 21:55:52 bx tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itemcount(char const *s, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (!s[i + 1] && s[i] != c))
			l++;
		i++;
	}
	return (l);
}

static void	ft_garbage(char **r)
{
	int	i;

	i = -1;
	while (r[i++])
		free(r[i]);
	free(r[i]);
	free(r);
	return ;
}

static void	ft_itemplace(char const *s, char c, char **r)
{
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	while (s[++i])
	{
		if (s[i] == c)
			continue ;
		j = i;
		while (s[j] != c && s[j])
			j++;
		r[x] = ft_substr(s, i, (j - i));
		if (!r[x])
		{
			ft_garbage(r);
			return ;
		}
		x++;
		i = j - 1;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**r;

	if (!s)
		return (0);
	r = ft_calloc((ft_itemcount(s, c) + 1), sizeof(char *));
	if (!r)
		return (0);
	ft_itemplace(s, c, r);
	return (r);
}
