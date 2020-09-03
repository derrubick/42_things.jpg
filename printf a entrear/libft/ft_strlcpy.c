/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:49:45 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:49:47 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t count;
	size_t source;

	count = 0;
	if (!dst || !src)
		return (0);
	source = ft_strlen((char*)src);
	if (dstsize == 0)
		return (source);
	while (src[count] && count < (dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (source);
}
