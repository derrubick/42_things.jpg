/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:50:06 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:50:07 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	x;
	unsigned char	y;

	count = 0;
	if (n == 0)
		return (0);
	while (s1[count] == s2[count] && count < (n - 1) && s1[count] && s2[count])
		count++;
	x = (unsigned char)s1[count];
	y = (unsigned char)s2[count];
	return (x - y);
}
