/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:48:26 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:48:28 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t count;

	if (!dst && !src)
		return ((char*)dst);
	if (dst <= src)
	{
		count = 0;
		while (count < len)
		{
			((unsigned char*)dst)[count] = ((unsigned char*)src)[count];
			count++;
		}
	}
	else
	{
		while (len--)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	}
	return ((void*)dst);
}
