/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:29:55 by mtrembla          #+#    #+#             */
/*   Updated: 2022/05/25 10:01:03 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	ft_flafla(void)
{
	ft_putstr_fd("\nWelcome to Minitalk!\n", 1);
	ft_putstr_fd("Your process ID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n-------------------------------", 1);
	write (1, "\n", 1);
}

static void	ft_sig_printer(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				byte;

	(void)context;
	if (byte == 0)
		byte = 8;
	if (sig == SIGUSR2)
		sig = 0;
	else if (sig == SIGUSR1)
		sig = 1;
	byte--;
	c += (sig & 1) << byte;
	if (byte == 0)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write (1, &c, 1);
		byte = 8;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	si;

	ft_flafla();
	si.sa_sigaction = ft_sig_printer;
	si.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause();
	return (0);
}
