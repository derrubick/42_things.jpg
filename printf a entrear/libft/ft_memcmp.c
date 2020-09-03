/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:48:12 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:48:14 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*a;
	unsigned char	*b;

	count = 0;
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	while (a[count] == b[count] && (count + 1) < n)
		count++;
	if (n == count)
		return (0);
	return (a[count] - b[count]);
}
