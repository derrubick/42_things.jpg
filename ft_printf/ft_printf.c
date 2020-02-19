/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:09:24 by vnastase          #+#    #+#             */
/*   Updated: 2020/02/19 12:47:35 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO crear una funcion que recorra un string, primero se verificaran las etiquetas despues de '%' luego de la ',' se hara un print
//tiene que gestionar
// c : Character
// s : String of characters
//: pointer addres (pasarlo por itoa base y castearlo a unsigned long int)
// d p  or i : signed decimal integer
// u : unsigned decimal integer
// x : unsigned hexadecimal integer
// X : unsigned hexadecimal integer (uppercase)
// % : un % seguido de otro % escribira un %
//

#include <stdio.h>
#include "ft_printf.h"

int		ft_printf(const char *line, ...)
{
	int		character_count;
	va_list	valist;

	va_start(valist, line);
	character_count = 0;
	while (*line)
	{
		if (*line == '%')
		{
			line++;
			if (*line == 'c')
				ft_case_c(valist, &character_count);
			else if (*line == 's')
				ft_case_s(valist, &character_count);
			else if (*line == 'p')
				ft_case_p(valist, &character_count);
			else if (*line == 'd' || *line == 'i')
				ft_case_id(valist, &character_count);
			else if (*line == 'u')
				ft_case_u(valist, &character_count);
			else if (*line == 'x')
				ft_case_x(valist, &character_count);
			else if (*line == 'X')
				ft_case_mx(valist, &character_count);
			else if (*line == '%')
				ft_case_percentage(valist, &character_count);
			else
				ft_last_case(valist, &character_count);
		}
		else
		{
			ft_putchar(*line);
			character_count++;
		}
		line++;
	}
	va_end(valist);
	return (character_count);
}

void	ft_case_c(va_list valist, int *character_count)
{
	char	print_char;

	print_char = va_arg(valist, int);
	ft_putchar(print_char);
	(*character_count)++;
}

void	ft_case_s(va_list valist, int *character_count)
{
	char *print_string;

	print_string = va_arg(valist, char *);
	ft_put_string(print_string);
	*character_count += ft_strlen(print_string);
}

void	ft_case_p(va_list valist, int *character_count)
{
	void		*pointer;
	char		*print_pointer;
	long int	address;

	pointer = (va_arg(valist, void*));
	address = (long int)pointer;
	print_pointer = ft_itoa_hex(address, 'W');
	ft_put_string("0x");
	ft_put_string(print_pointer);
	*character_count += ft_strlen(print_pointer);
}

void	ft_case_id(va_list valist, int *character_count)
{
	int	print_signed;

	print_signed = va_arg(valist, int);
	ft_putnbr_fd(print_signed);
	*character_count += ft_count_nb(print_signed);
}

void	ft_case_u(va_list valist, int *character_count)
{
	unsigned int print_unsigned;

	print_unsigned = va_arg(valist, unsigned int);
	ft_putnbr_fd(print_unsigned);
	*character_count += ft_count_nb(print_unsigned);
}

void	ft_case_x(va_list valist, int *character_count)
{
	int		hexnum;
	char	*num_print;

	hexnum = va_arg(valist, int);
	num_print = ft_itoa_hex(hexnum, 'W');
	ft_put_string(num_print);
	free(num_print);
	*character_count += ft_strlen(num_print);
}

void	ft_case_mx(va_list valist, int *character_count)
{
	int		hexnum;
	char	*num_print;

	hexnum = va_arg(valist, int);
	num_print = ft_itoa_hex(hexnum, '7');
	ft_put_string(num_print);
	free(num_print);
	*character_count += ft_strlen(num_print);
}

void	ft_case_percentage(va_list valist, int *character_count)
{
	ft_putchar('%');
	(*character_count)++;
}

void	ft_last_case(va_list valist, int *character_count)
{
	ft_putchar('%');
	(*character_count)++;
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

int main(int argc, char const *argv[])
{
	ft_printf("%p persona %%  letras\n", c);
	printf("%p persona %%  letras\n", c);
	return 0;
}
