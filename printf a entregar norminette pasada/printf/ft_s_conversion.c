/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:40:13 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:40:14 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags_wield(int *rst, t_flags n, char *str, int len)
{
	if (len > n.wield)
		ft_putstr_pft(rst, str, 1);
	else if (!n.minus && !n.zero)
	{
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
		ft_putstr_pft(rst, str, 1);
	}
	else if (!n.minus && n.zero)
	{
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, '0', 1);
		ft_putstr_pft(rst, str, 1);
	}
	else if (n.minus && !n.zero)
	{
		ft_putstr_pft(rst, str, 1);
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
	}
}

static void	ft_flags_mix_2(int *rst, t_flags n, char *str, int len)
{
	int cpy;
	int i;

	i = 0;
	cpy = n.lenght;
	if (!n.lenght && !str)
		ft_putchar_pft(rst, ' ', 1);
	else
	{
		while (str[i] && n.lenght--)
			ft_putchar_pft(rst, str[i++], 1);
	}
	if (cpy > len)
		while (((n.wield--) - len) > 0)
			ft_putchar_pft(rst, ' ', 1);
	else
		while (((n.wield--) - cpy) > 0)
			ft_putchar_pft(rst, ' ', 1);
}

static void	ft_flags_mix(int *rst, t_flags n, char *str, int len)
{
	int i;

	i = 0;
	if (!n.minus)
	{
		if (n.lenght > len)
			while (((n.wield--) - len) > 0)
				ft_putchar_pft(rst, ' ', 1);
		else
			while (((n.wield--) - n.lenght) > 0)
				ft_putchar_pft(rst, ' ', 1);
		if (!n.lenght && !str)
		{
			ft_putchar_pft(rst, ' ', 1);
			return ;
		}
		while (str[i] && n.lenght--)
			ft_putchar_pft(rst, str[i++], 1);
	}
	else if (n.minus)
		ft_flags_mix_2(rst, n, str, len);
}

static void	ft_flags(int *rst, t_flags n, char *str)
{
	int len;
	int i;

	if (!str)
		str = "(null)";
	n.wield < 0 ? (n.minus = 1 && (n.wield *= -1)) : 0;
	n.lenght < 0 ? (n.point = 0) : 0;
	len = ft_strlen(str);
	i = 0;
	if (!n.wield && !n.point)
		ft_putstr_pft(rst, str, 1);
	else if (n.wield && !n.point)
		ft_flags_wield(rst, n, str, len);
	else if (n.point && !n.wield)
		while (str[i] != str[len] && n.lenght--)
			ft_putchar_pft(rst, str[i++], 1);
	else if (n.point && n.wield)
		ft_flags_mix(rst, n, str, len);
}

void		ft_s_conversion(int *rst, char *p, char *str, ...)
{
	va_list	list;
	int		i;
	t_flags	n;

	i = 0;
	va_start(list, str);
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
	ft_flags(rst, n, str);
}
