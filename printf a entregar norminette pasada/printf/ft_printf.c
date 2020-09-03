/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:39:57 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:39:58 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_hex_cv(const char *n, t_printf x, int *rst, va_list list)
{
	if ((n[x.i] == 'x') && x.count == 0)
		ft_x_conversion(rst, x.p, va_arg(list, long int));
	else if ((n[x.i] == 'x') && x.count == 1)
		ft_x_conversion(rst, x.p, va_arg(list, long int), x.wildcard[0]);
	else if ((n[x.i] == 'x') && x.count == 2)
		ft_x_conversion(rst, x.p, va_arg(list, long int), x.wildcard[0],
				x.wildcard[1]);
	if ((n[x.i] == 'X') && x.count == 0)
		ft_x2_conversion(rst, x.p, va_arg(list, long int));
	else if ((n[x.i] == 'X') && x.count == 1)
		ft_x2_conversion(rst, x.p, va_arg(list, long int), x.wildcard[0]);
	else if ((n[x.i] == 'X') && x.count == 2)
		ft_x2_conversion(rst, x.p, va_arg(list, long int), x.wildcard[0],
				x.wildcard[1]);
	if ((n[x.i] == 'p') && x.count == 0)
		ft_p_conversion(rst, x.p, va_arg(list, void *));
	else if ((n[x.i] == 'p') && x.count == 1)
		ft_p_conversion(rst, x.p, va_arg(list, void *), x.wildcard[0]);
	else if ((n[x.i] == 'p') && x.count == 2)
		ft_s_conversion(rst, x.p, va_arg(list, void *), x.wildcard[0],
				x.wildcard[1]);
}

static void		ft_int_cv(const char *n, t_printf x, int *rst, va_list list)
{
	if ((n[x.i] == 'd' || n[x.i] == 'i') && x.count == 0)
		ft_d_conversion(rst, x.p, va_arg(list, int));
	else if ((n[x.i] == 'd' || n[x.i] == 'i') && x.count == 1)
		ft_d_conversion(rst, x.p, va_arg(list, int), x.wildcard[0]);
	else if ((n[x.i] == 'd' || n[x.i] == 'i') && x.count == 2)
		ft_d_conversion(rst, x.p, va_arg(list, int), x.wildcard[0],
				x.wildcard[1]);
	if ((n[x.i] == 'u') && x.count == 0)
		ft_u_conversion(rst, x.p, va_arg(list, unsigned int));
	else if ((n[x.i] == 'u') && x.count == 1)
		ft_u_conversion(rst, x.p, va_arg(list, unsigned int),
				x.wildcard[0]);
	else if ((n[x.i] == 'u') && x.count == 2)
		ft_u_conversion(rst, x.p, va_arg(list, unsigned int),
				x.wildcard[0],
				x.wildcard[1]);
}

static void		ft_char_cv(const char *n, t_printf x, int *rst, va_list list)
{
	if ((n[x.i] == 'c') && x.count == 0)
		ft_c_conversion(rst, x.p, va_arg(list, int));
	else if ((n[x.i] == 'c') && x.count == 1)
		ft_c_conversion(rst, x.p, va_arg(list, int), x.wildcard[0]);
	if ((n[x.i] == '\%') && x.count == 0)
		ft_pct_conversion(rst, x.p);
	else if ((n[x.i] == '\%') && x.count == 1)
		ft_pct_conversion(rst, x.p, x.wildcard[0]);
	if ((n[x.i] == 's') && x.count == 0)
		ft_s_conversion(rst, x.p, va_arg(list, char *));
	else if ((n[x.i] == 's') && x.count == 1)
		ft_s_conversion(rst, x.p, va_arg(list, char *), x.wildcard[0]);
	else if ((n[x.i] == 's') && x.count == 2)
		ft_s_conversion(rst, x.p, va_arg(list, char *), x.wildcard[0],
				x.wildcard[1]);
}

static void		ft_conversion(const char *n, t_printf *x, va_list list)
{
	x->i++;
	x->j = 0;
	while (!x->p[x->j])
		x->p[x->j++] = 0;
	x->j = 0;
	while ((n[x->i] >= '0' && n[x->i] <= '9') || n[x->i] == '*' ||
			n[x->i] == '-' || n[x->i] == '.')
	{
		(n[x->i] == '*') ? (x->wildcard[x->count++] = va_arg(list, int)) : 0;
		x->p[x->j++] = n[x->i++];
	}
	x->p[x->j] = 0;
	ft_hex_cv(n, *x, &x->rst, list);
	ft_int_cv(n, *x, &x->rst, list);
	ft_char_cv(n, *x, &x->rst, list);
	x->i++;
	x->count = 0;
}

int				ft_printf(const char *n, ...)
{
	va_list		list;
	t_printf	x;

	x.rst = 0;
	va_start(list, n);
	x.i = 0;
	x.count = 0;
	while (n[x.i] != 0)
		if (n[x.i] == '%')
			ft_conversion(n, &x, list);
		else
		{
			x.rst++;
			write(1, &n[x.i++], 1);
		}
	va_end(list);
	return (x.rst);
}
