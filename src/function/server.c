/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:30:47 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/25 11:59:17 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	create_malloc(char c, char **s, int *l)
{
	if (c >= '0' && c <= '9')
		*l = ((*l) * 10) + (c - 48);
	else
		*s = (char *)malloc((sizeof(char) * (*l)) + 1);
}

void	create_string(char c, char **s, int *i)
{
	(*s)[*i] = c;
	(*i)++;
}

void	print_string(char **s, int *i, int *l)
{
	write(1, *s, *l);
	free(*s);
	*s = 0;
	*i = 0;
	*l = 0;
}

void	socket(int signal)
{
	static int	c;
	static int	b;
	static char	*s;
	static int	l;
	static int	i;

	if (signal == SIGUSR1)
		c |= (1 << b);
	if (++b == 8)
	{
		if (!s)
			create_malloc(c, &s, &l);
		else
		{
			create_string(c, &s, &i);
			if (!c)
				print_string(&s, &i, &l);
		}
		b = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\033[31;1;4mPID: %d\033[0m\n", pid);
	while (1)
	{
		signal(SIGUSR1, socket);
		signal(SIGUSR2, socket);
		pause();
	}
}
