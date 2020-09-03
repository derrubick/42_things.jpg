/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:49:40 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:49:41 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	count;

	ds = 0;
	while (dst[ds] && ds < dstsize)
		ds++;
	count = 0;
	while ((count + ds + 1) < dstsize && src[count])
	{
		dst[count + ds] = src[count];
		count++;
	}
	if ((ds + count) < dstsize)
		dst[count + ds] = '\0';
	return (ds + ft_strlen(src));
}
