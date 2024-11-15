/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:26:04 by tbarret           #+#    #+#             */
/*   Updated: 2023/12/05 14:56:33 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_sign(char *str, long *nb)
{
	if ((*nb) == 0)
		str[0] = '0';
	if ((*nb) < 0)
	{
		str[0] = '-';
		*nb = -*nb;
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		modulus;
	short int	maiboyerlpb;
	char		str[13];
	long		nb;

	nb = n;
	maiboyerlpb = 0;
	modulus = 1000000000;
	ft_bzero(str, 13);
	i = ft_check_sign(str, &nb);
	while (modulus != 0)
	{
		if (nb / modulus != 0 || maiboyerlpb != 0)
		{
			str[i++] = (nb / modulus) + 48;
			maiboyerlpb++;
		}
		nb %= modulus;
		modulus /= 10;
	}
	return (ft_strdup(str));
}
