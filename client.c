/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:28:52 by mtrembla          #+#    #+#             */
/*   Updated: 2022/05/24 13:20:12 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static void	ft_handler(int signum)
{
	(void)signum;
	ft_putendl_fd("Signal Sent", 1);
	exit(EXIT_SUCCESS);
}

static void	ft_encoding(char *str, pid_t pid)
{
	int	len;
	int	byte;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		byte = 8;
		while(byte)
		{
			byte--;
			if ((*str >> byte & 1) == 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_putstr_fd("Number of arguments incorrect\n", 1);
		return(-1);
	}
	if (!ft_strlen(argv[2]))
		ft_putstr_fd("You're trying to send an empty string...\nI'll allow it\n", 1);
	if (pid < 1 || pid > 99998)
	{
		ft_putstr_fd("PID is invalid\n", 1);
		return (-1);
	}
	signal(SIGUSR1, ft_handler);
	ft_encoding(argv[2], pid);
}
