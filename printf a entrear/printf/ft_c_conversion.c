/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:37:48 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:37:50 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	ft_flags_wield(int *rst, t_flags n, int wd)
{
	if (!n.minus)
	{
		while (((n.wield--) - 1) > 0)
			ft_putchar_pft(rst, ' ', 1);
		ft_putchar_pft(rst, wd, 1);
	}
	else if (n.minus)
	{
		ft_putchar_pft(rst, wd, 1);
		while (((n.wield--) - 1) > 0)
			ft_putchar_pft(rst, ' ', 1);
	}
}

static void	ft_flags(int *rst, t_flags n, int wd)
{
	n.wield < 0 ? (n.minus = 1 && (n.wield *= -1)) : 0;
	n.lenght < 0 ? (n.point = 0) : 0;
	if (!n.wield)
		ft_putchar_pft(rst, wd, 1);
	else if (n.wield)
		ft_flags_wield(rst, n, wd);
}

void		ft_c_conversion(int *rst, char *p, int wd, ...)
{
	va_list	list;
	int		i;
	t_flags	n;

	i = 0;
	va_start(list, wd);
	n.wield = 0;
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
	ft_flags(rst, n, wd);
}
