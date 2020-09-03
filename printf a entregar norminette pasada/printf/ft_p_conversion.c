/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:39:41 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:39:43 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags_mix(int *rst, t_flags n, void *ad, int len)
{
	if (!n.lenght && !ad)
		len = 2;
	if (n.lenght > len)
		while (((n.wield--) - n.lenght) > 0)
			ft_putchar_pft(rst, ' ', 1);
	else
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
	write(1, "0x", 2);
	(*rst) += 2;
	if (!n.lenght && !ad)
		return ;
	while (((n.lenght--) - (len - 2)) > 0)
		ft_putchar_pft(rst, '0', 1);
	ft_hexa(rst, (unsigned long)ad, 87);
}

static void	ft_flags_wield(int *rst, t_flags n, void *ad, int len)
{
	if (!n.minus)
	{
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
		write(1, "0x", 2);
		(*rst) += 2;
		ft_hexa(rst, (unsigned long)ad, 87);
	}
	else if (n.minus)
	{
		write(1, "0x", 2);
		(*rst) += 2;
		ft_hexa(rst, (unsigned long)ad, 87);
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
	}
}

static void	ft_flags(int *rst, t_flags n, void *ad)
{
	int len;

	len = ft_hexa_len((unsigned long)ad, 87);
	n.wield < 0 ? (n.minus = 1 && (n.wield *= -1)) : 0;
	n.lenght < 0 ? (n.point = 0) : 0;
	if (!n.wield && !n.point)
	{
		write(1, "0x", 2);
		(*rst) += 2;
		ft_hexa(rst, (unsigned long)ad, 87);
	}
	else if (n.wield && !n.point)
		ft_flags_wield(rst, n, ad, len);
	else if (n.point && !n.wield)
	{
		write(1, "0x", 2);
		(*rst) += 2;
		if (!n.lenght && !ad)
			return ;
		while (((n.lenght--) - (len - 2)) > 0 && n.lenght >= (len - 2))
			ft_putchar_pft(rst, '0', 1);
		ft_hexa(rst, (unsigned long)ad, 87);
	}
	else if (n.point && n.wield)
		ft_flags_mix(rst, n, ad, len);
}

void		ft_p_conversion(int *rst, char *p, void *ad, ...)
{
	va_list	list;
	int		i;
	t_flags	n;

	i = 0;
	va_start(list, ad);
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
	ft_flags(rst, n, ad);
}
