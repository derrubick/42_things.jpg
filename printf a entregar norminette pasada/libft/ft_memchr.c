/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:48:06 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:48:08 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*x;
	unsigned char	y;

	x = (unsigned char*)s;
	y = (unsigned char)c;
	count = 0;
	while (x[count] && count < n && x[count] != y)
		count++;
	if ((x[count] || x[count] == y) && count < n)
	{
		x += count;
		return (x);
	}
	return (0);
}
