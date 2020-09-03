/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:48:01 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:48:03 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*x;
	unsigned char	*y;
	unsigned char	t;

	count = 0;
	x = dst;
	y = (unsigned char*)src;
	t = (unsigned char)c;
	while (count != n && y[count] != t)
	{
		x[count] = y[count];
		count++;
	}
	if (y[count] == t)
	{
		x[count] = y[count];
		x += count + 1;
		return (x);
	}
	return (0);
}
