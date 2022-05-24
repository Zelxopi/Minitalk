/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 07:28:42 by mtrembla          #+#    #+#             */
/*   Updated: 2021/09/01 16:06:31 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Transforme minuscule en majuscule
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
