/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   client.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tbarret <tbarret@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/03 20:27:58 by tbarret		   #+#	#+#			 */
/*   Updated: 2024/02/03 20:27:58 by tbarret		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/minitalk.h"

static void	receive(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR2)
		write(1,
			"\033[32mThe server successfully received the message !\033[0m\n", 55);
}

static void	socket(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

static void	socket_size(int pid, int size)
{
	char	*r;
	size_t	i;

	i = 0;
	r = ft_itoa(size);
	while (r[i])
	{
		socket(pid, r[i]);
		i++;
	}
	free(r);
}

static void	socket_ack(void)
{
	struct sigaction	action;

	action.sa_sigaction = &receive;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3 && pid)
	{
		socket_ack();
		socket_size(pid, ft_strlen(argv[2]));
		socket(pid, '\0');
		while (argv[2][i])
		{
			socket(pid, argv[2][i]);
			i++;
		}
		socket(pid, '\0');
	}
	else
		ft_printf("\033[31mSyntaxe: \033[31;1;4m%s <PID> <MSG>\033[0m\n",
			argv[0]);
	return (0);
}
