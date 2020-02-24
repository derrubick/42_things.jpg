/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:23:40 by vnastase          #+#    #+#             */
/*   Updated: 2019/12/11 12:25:02 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;

	if (!(dest = (char *)malloc(((sizeof(char)) * (len + 1)))))
		return (NULL);
	if (!s)
		return (NULL);
	if ((start >= (ft_strlen(s))))
    {
        free(dest);
		return (ft_strdup(""));
    }
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
