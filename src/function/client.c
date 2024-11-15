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

void	socket(int pid, char c)
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

void	socket_size(int pid, int size)
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

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3 && pid)
	{
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
