/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:45:19 by vnastase          #+#    #+#             */
/*   Updated: 2020/02/24 12:50:36 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_hex(long int num, int w)
{
	int					len;
	unsigned long int	aux;
	char				*str;

	len = 1;
	aux = num;
	while (aux /= 16)
		len++;
	if (!(str = malloc(len + 1)))
		return (0);
	str[len] = 0;
	while (len--)
	{
		if ((num % 16) < 10)
			str[len] = num % 16 + '0';
		if ((num % 16) > 9)
			str[len] = num % 16 + w;
		num /= 16;
	}
	return (str);
}

int		ft_count_nb(int nb)
{
	int				count;
	unsigned int	c;

	c = 0;
	count = 0;
	if (nb < 0)
	{
		c = nb * -1;
		count++;
	}
	if (nb > 0)
		c = nb;
	while (c >= 10)
	{
		c = c / 10;
		count++;
	}
	if (c < 10)
		count++;
	return (count);
}

int		ft_strlen(char *string)
{
	int i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_string(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		ft_putchar(string[i]);
		i++;
	}
}

void	ft_putnbr_fd(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10);
	ft_putchar((char)(nbr % 10 + 48));
}
