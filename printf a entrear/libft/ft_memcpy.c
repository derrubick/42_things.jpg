/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:48:18 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:48:19 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*x;
	char			*y;

	if (!dst && !src)
		return (dst);
	x = (char*)dst;
	y = (char*)src;
	while (n--)
		*x++ = *y++;
	return (dst);
}
