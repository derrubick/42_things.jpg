/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:48:35 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:48:36 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *dest, int ch, size_t len)
{
	size_t			count;
	unsigned char	*x;

	x = dest;
	count = 0;
	while (count != len)
	{
		x[count] = ch;
		count++;
	}
	return ((void*)dest);
}
