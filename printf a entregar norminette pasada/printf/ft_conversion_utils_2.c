/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:38:27 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:42:14 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_hexa(int *rst, long int decimal, int i)
{
	long int			buff;
	long unsigned int	dec;
	int					j;
	char				hex[100];

	dec = (long unsigned int)decimal;
	j = 0;
	if (!decimal)
	{
		hex[j++] = 48;
		ft_putchar_pft(rst, hex[--j], 1);
		return (0);
	}
	while (dec != 0)
	{
		buff = dec % 16;
		if (buff < 10)
			hex[j++] = 48 + buff;
		else
			hex[j++] = i + buff;
		dec /= 16;
	}
	while (j-- > 0)
		ft_putchar_pft(rst, hex[j], 1);
	return (0);
}

int			ft_hexa_len(long int decimal, int i)
{
	long int			buff;
	long unsigned int	dec;
	int					j;
	char				hex[100];

	j = 0;
	dec = (long unsigned int)decimal;
	if (!decimal)
	{
		hex[j++] = 0 + 48;
		return (j + 2);
	}
	while (dec != 0)
	{
		buff = dec % 16;
		if (buff < 10)
			hex[j++] = 48 + buff;
		else
			hex[j++] = i + buff;
		dec = dec / 16;
	}
	return (j + 2);
}

void		ft_putunsigned_pft(int *rst, unsigned int n, int fd)
{
	unsigned int	a;
	unsigned int	x;

	x = n;
	if (x >= 10)
		ft_putnbr_pft(rst, x / 10, fd);
	a = x % 10 + 48;
	(*rst)++;
	write(fd, &a, 1);
}

static int	ft_space(unsigned int n)
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

char		*ft_utoa(unsigned int n)
{
	int				ct;
	int				len;
	unsigned int	nb;
	char			*rst;

	ct = 0;
	nb = n;
	len = ft_space(nb);
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
