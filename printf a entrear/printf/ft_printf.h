/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:40:05 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:40:07 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_flags
{
	int zero;
	int minus;
	int point;
	int wield;
	int lenght;
}						t_flags;

typedef struct			s_printf
{
	int		i;
	int		j;
	char	p[20];
	int		count;
	int		wildcard[2];
	int		rst;
}						t_printf;

int						ft_printf(const char *n, ...);
void					ft_d_conversion(int *rst, char *p, int nb, ...);
void					ft_u_conversion(int *rst, char *p, unsigned
int nb, ...);
void					ft_c_conversion(int *rst, char *p, int wd, ...);
void					ft_pct_conversion(int *rst, char *p, ...);
void					ft_s_conversion(int *rst, char *p, char *str, ...);
void					ft_p_conversion(int *rst, char *p, void *ad, ...);
void					ft_x_conversion(int *rst, char *p, long int hex, ...);
void					ft_x2_conversion(int *rst, char *p, long int hex, ...);
void					ft_putnbr_pft(int *rst, int n, int fd);
void					ft_putchar_pft(int *rst, int c, int fd);
int						ft_ifnegative_pft(int *rst, int fd, int *nb, int *len);
void					ft_putstr_pft(int *rst, char *s, int fd);
int						ft_hex(int *rst, long int decimal, int i);
int						ft_hexa(int *rst, long int decimal, int i);
int						ft_hexa_len(long int decimal, int i);
char					*ft_utoa(unsigned int n);
void					ft_putunsigned_pft(int *rst, unsigned int n,
		int fd);

#endif
