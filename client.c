/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:28:52 by mtrembla          #+#    #+#             */
/*   Updated: 2022/05/22 16:09:54 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "LibFT/libft.h"

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

	(void)argc;
	pid = ft_atoi(argv[1]);
	ft_encoding(argv[2], pid);
}