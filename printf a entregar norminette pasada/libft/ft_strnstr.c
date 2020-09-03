/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:50:11 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:50:12 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	count;
	size_t	nedco;
	char	*hs;

	count = -1;
	if (!len && !neddle)
		return (0);
	if (!*neddle)
		return ((char*)haystack);
	hs = (char*)haystack;
	while (haystack[++count] && count < len)
	{
		if (haystack[count] == neddle[0])
		{
			nedco = 0;
			while (neddle[nedco] == haystack[count + nedco] &&
					haystack[count + nedco] &&
					(count + nedco) < len)
			{
				if (!neddle[++nedco])
					return (hs + count);
			}
		}
	}
	return (0);
}
