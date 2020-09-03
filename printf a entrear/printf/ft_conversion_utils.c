/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:38:15 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:42:47 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pft(int *rst, int n, int fd)
{
	int				a;
	unsigned int	x;

	if (n < 0)
	{
		write(fd, "-", 1);
		(*rst)++;
		x = n * -1;
	}
	else
		x = n;
	if (x >= 10)
		ft_putnbr_pft(rst, x / 10, fd);
	a = x % 10 + 48;
	(*rst)++;
	write(fd, &a, 1);
}

void	ft_putchar_pft(int *rst, int c, int fd)
{
	write(fd, &c, 1);
	(*rst)++;
}

int		ft_ifnegative_pft(int *rst, int fd, int *nb, int *len)
{
	if (*nb < 0)
	{
		(*nb) *= -1;
		(*len)--;
		ft_putchar_pft(rst, '-', fd);
		return (1);
	}
	return (0);
}

void	ft_putstr_pft(int *rst, char *s, int fd)
{
	int i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != 0)
	{
		write(fd, &s[i++], 1);
		(*rst)++;
	}
}

int		ft_hex(int *rst, long int decimal, int i)
{
	long int			buff;
	unsigned int		dec;
	int					j;
	char				hex[100];

	dec = (unsigned int)decimal;
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
