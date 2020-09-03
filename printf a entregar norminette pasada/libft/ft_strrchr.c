/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:50:16 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:50:17 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	t;
	size_t	count;

	t = (char)c;
	count = ft_strlen((char*)s);
	while (count > 0)
	{
		if (s[count] == t)
			return ((char*)(s + count));
		count--;
	}
	if (s[0] == c)
		return ((char*)s);
	return (0);
}
