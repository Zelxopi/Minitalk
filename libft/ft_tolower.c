/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 07:35:04 by mtrembla          #+#    #+#             */
/*   Updated: 2021/09/01 16:07:04 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Transforme Majuscule en minuscule
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
