/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x2_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:40:54 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:40:57 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags_mix_2(int *rst, t_flags n, long int hex, int len)
{
	int cpy;

	cpy = n.lenght;
	if (!n.lenght && !hex)
		ft_putchar_pft(rst, ' ', 1);
	else
	{
		while (((cpy--) - len) > 0)
			ft_putchar_pft(rst, '0', 1);
		ft_hex(rst, (unsigned long)hex, 55);
	}
	if (n.lenght > len)
		while (((n.wield--) - n.lenght) > 0)
			ft_putchar_pft(rst, ' ', 1);
	else
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
}

static void	ft_flags_mix(int *rst, t_flags n, long int hex, int len)
{
	if (!n.minus)
	{
		if (n.lenght > len)
			while (((n.wield--) - n.lenght) > 0)
				ft_putchar_pft(rst, ' ', 1);
		else
			while (((n.wield--) - len) > 0)
				ft_putchar_pft(rst, ' ', 1);
		if (!n.lenght && !hex)
		{
			ft_putchar_pft(rst, ' ', 1);
			return ;
		}
		while (((n.lenght--) - len) > 0)
			ft_putchar_pft(rst, '0', 1);
		ft_hex(rst, (unsigned long)hex, 55);
	}
	else if (n.minus)
		ft_flags_mix_2(rst, n, hex, len);
}

static void	ft_flags_wield(int *rst, t_flags n, long int hex, int len)
{
	if (!n.minus)
	{
		if (n.zero)
			while (((n.wield--) - len) > 0)
				ft_putchar_pft(rst, '0', 1);
		else
			while (((n.wield--) - len) > 0)
				ft_putchar_pft(rst, ' ', 1);
		ft_hex(rst, hex, 55);
	}
	else if (n.minus)
	{
		ft_hex(rst, hex, 55);
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
	}
}

static void	ft_flags(int *rst, t_flags n, long int hex)
{
	int len;

	len = ft_hexa_len(hex, 55) - 2;
	n.wield < 0 ? (n.minus = 1 && (n.wield *= -1)) : 0;
	n.lenght < 0 ? (n.point = 0) : 0;
	if (!n.wield && !n.point)
		ft_hex(rst, hex, 55);
	else if (n.wield && !n.point)
		ft_flags_wield(rst, n, hex, len);
	else if (n.point && !n.wield)
	{
		if (!n.lenght && !hex)
			return ;
		while (((n.lenght--) - len) > 0 && n.lenght >= len)
			ft_putchar_pft(rst, '0', 1);
		ft_hex(rst, (unsigned long)hex, 55);
	}
	else if (n.point && n.wield)
		ft_flags_mix(rst, n, hex, len);
}

void		ft_x2_conversion(int *rst, char *p, long int hex, ...)
{
	va_list	list;
	int		i;
	t_flags	n;

	i = 0;
	va_start(list, hex);
	n.lenght = 0;
	if ((n.zero = (p[i] == '0') ? 1 : 0))
		i++;
	if ((n.minus = (p[i] == '-') ? 1 : 0))
		while (p[i] == '-')
			i++;
	if ((n.wield = (p[i] == '*') ? va_arg(list, int) : 0))
		i++;
	while (p[i] >= '0' && p[i] <= '9')
		n.wield = (n.wield * 10) + (p[i++] - 48);
	if ((n.point = (p[i] == '.') ? 1 : 0))
	{
		if ((n.lenght = (p[++i] == '*') ? va_arg(list, int) : 0))
			i++;
		while (p[i] >= '0' && p[i] <= '9')
			n.lenght = (n.lenght * 10) + (p[i++] - 48);
	}
	va_end(list);
	ft_flags(rst, n, hex);
}
