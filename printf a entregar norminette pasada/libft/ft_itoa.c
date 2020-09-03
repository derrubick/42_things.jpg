/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:46:58 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:47:01 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_space(long int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i++);
}

char		*ft_itoa(int n)
{
	int				ct;
	int				len;
	long int		nb;
	char			*rst;

	ct = 0;
	nb = n;
	len = ft_space(nb);
	if (nb < 0)
	{
		ct++;
		nb *= -1;
	}
	if ((rst = malloc((len + 1) * sizeof(char))) == 0)
		return (0);
	rst[len] = 0;
	rst[0] = '0';
	if (ct == 1)
		rst[0] = '-';
	while (nb > 0)
	{
		rst[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (rst);
}
