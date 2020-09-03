/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:50:25 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:50:27 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_isall(char const *s1, char const *set, int *a, int *f)
{
	int i;

	i = 0;
	*a = 0;
	*f = 0;
	if (ft_strlen(set) == 0)
		return (0);
	while (*s1 != 0)
	{
		while (set[i] != 0)
			if (*s1 != set[i++])
				return (0);
		i = 0;
		s1++;
	}
	return (1);
}

static int	ft_pass(char const *s1, char const *set, int f)
{
	int j;

	j = 0;
	if (s1[f] == set[0])
		return (1);
	while (set[j] != 0 && s1[f] != set[j++])
		if (s1[f] == set[j])
			return (1);
	return (0);
}

static int	ft_msize(char const *s1, char const *set)
{
	int		i;
	int		f;
	int		len;

	i = 0;
	f = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (len);
	if (!set)
		return (len);
	while (s1[f] != 0 && ft_pass(s1, set, f) == 1)
		f++;
	if (f - len == 0)
		return (1);
	while (ft_pass(s1, set, len) == 1 && len > 0)
		len--;
	return (len - f + 2);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		f;
	char	*rst;
	int		len;

	if (s1 == 0)
		return (0);
	len = ft_strlen(s1);
	if (ft_isall(s1, set, &i, &f) && set)
	{
		if (!(rst = malloc(sizeof(char))))
			return (0);
		rst[0] = 0;
		return (rst);
	}
	if ((rst = malloc(ft_msize(s1, set) * sizeof(char))) == 0)
		return (0);
	while (s1[f] != 0 && ft_pass(s1, set, f) == 1)
		f++;
	while (ft_pass(s1, set, len) == 1)
		len--;
	while (f <= len && s1[f] != 0)
		rst[i++] = s1[f++];
	rst[i] = 0;
	return (rst);
}
