/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:41:39 by mtrembla          #+#    #+#             */
/*   Updated: 2021/09/09 18:58:00 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*s = string à écrire
fd = fd sur lequel écrire
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write (fd, s++, 1);
	}
}
