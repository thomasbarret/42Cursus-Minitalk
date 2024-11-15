/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:30:47 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/25 13:06:31 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static void	create_malloc(char c, char **s, int *l)
{
	if (c >= '0' && c <= '9')
		*l = ((*l) * 10) + (c - 48);
	else
		*s = (char *)malloc((sizeof(char) * (*l)) + 1);
}

static void	create_string(char c, char **s, int *i)
{
	(*s)[*i] = c;
	(*i)++;
}

static void	print_string(char **s, int *i, int *l, siginfo_t *info)
{
	write(1, *s, *l);
	kill(info->si_pid, SIGUSR2);
	free(*s);
	*s = NULL;
	*i = 0;
	*l = 0;
}

static void	socket(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	b;
	static char	*s;
	static int	l;
	static int	i;

	(void)context;
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
				print_string(&s, &i, &l, info);
		}
		b = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("\033[31;1;4mPID: %d\033[0m\n", pid);
	action.sa_sigaction = &socket;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
