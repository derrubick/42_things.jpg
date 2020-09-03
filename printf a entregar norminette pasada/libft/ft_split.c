/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:49:10 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:49:12 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		countw(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char		*ft_mallocw(char *s, char c)
{
	char	*rst;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	rst = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		rst[i] = s[i];
		i++;
	}
	rst[i] = '\0';
	return (rst);
}

char			**ft_split(char const *s, char c)
{
	char	*sc;
	char	**rst;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	sc = (char *)s;
	rst = (char **)malloc(sizeof(char *) * (countw(sc, c) + 1));
	if (rst == 0)
		return (0);
	while (*sc)
	{
		while (*sc && *sc == c)
			sc++;
		if (*sc && *sc != c)
		{
			rst[i++] = ft_mallocw(sc, c);
			while (*sc && *sc != c)
				sc++;
		}
	}
	rst[i] = 0;
	return (rst);
}
