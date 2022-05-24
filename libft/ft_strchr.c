/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 07:42:05 by mtrembla          #+#    #+#             */
/*   Updated: 2021/09/02 14:04:43 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//cherche première occurence du caractère
char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
