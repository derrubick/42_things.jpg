/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:40:20 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:40:22 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void	ft_flags_wield(int *rst, t_flags n, unsigned int nb, int len)
{
	if (len > n.wield)
		ft_putunsigned_pft(rst, nb, 1);
	else if (!n.minus && !n.zero)
	{
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
		ft_putunsigned_pft(rst, nb, 1);
	}
	else if (!n.minus && n.zero)
	{
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, '0', 1);
		ft_putunsigned_pft(rst, nb, 1);
	}
	else if (n.minus && !n.zero)
	{
		ft_putunsigned_pft(rst, nb, 1);
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
	}
}

static void	ft_flags_mix_2(int *rst, t_flags n, unsigned int nb, int len)
{
	int cpy;

	cpy = n.lenght;
	if (nb >= 0)
		n.point = 0;
	if (!n.lenght && !nb)
		ft_putchar_pft(rst, ' ', 1);
	else
	{
		while (((n.lenght--) - len) > 0)
			ft_putchar_pft(rst, '0', 1);
		ft_putunsigned_pft(rst, nb, 1);
	}
	if (cpy > len)
		while (((n.wield--) - cpy) > n.point)
			ft_putchar_pft(rst, ' ', 1);
	else
		while (((n.wield--) - len) > n.point)
			ft_putchar_pft(rst, ' ', 1);
}

static void	ft_flags_mix(int *rst, t_flags n, unsigned int nb, int len)
{
	if (!n.minus)
	{
		if (nb >= 0)
			n.point = 0;
		if (n.lenght > len)
			while (((n.wield--) - n.lenght) > n.point)
				ft_putchar_pft(rst, ' ', 1);
		else
			while (((n.wield--) - len) > 0)
				ft_putchar_pft(rst, ' ', 1);
		if (!n.lenght && !nb)
		{
			ft_putchar_pft(rst, ' ', 1);
			return ;
		}
		while (((n.lenght--) - len) > 0)
			ft_putchar_pft(rst, '0', 1);
		ft_putunsigned_pft(rst, nb, 1);
	}
	else if (n.minus)
		ft_flags_mix_2(rst, n, nb, len);
}

static void	ft_flags(int *rst, t_flags n, unsigned int nb)
{
	int len;

	len = ft_strlen(ft_utoa(nb));
	n.wield < 0 ? (n.minus = 1 && (n.wield *= -1)) : 0;
	n.lenght < 0 ? (n.point = 0) : 0;
	if (!nb && !n.lenght && n.point && !n.wield)
		return ;
	if (!n.wield && !n.point)
		ft_putunsigned_pft(rst, nb, 1);
	else if (n.wield && !n.point)
		ft_flags_wield(rst, n, nb, len);
	else if (n.point && !n.wield)
	{
		while (((n.lenght--) - len) > 0 && n.lenght >= len)
			ft_putchar_pft(rst, '0', 1);
		ft_putunsigned_pft(rst, nb, 1);
	}
	else if (n.point && n.wield)
		ft_flags_mix(rst, n, nb, len);
}

void		ft_u_conversion(int *rst, char *p, unsigned int nb, ...)
{
	va_list	list;
	int		i;
	t_flags	n;

	i = 0;
	va_start(list, nb);
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
	ft_flags(rst, n, nb);
}
