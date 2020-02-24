/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:09:24 by vnastase          #+#    #+#             */
/*   Updated: 2020/02/24 12:51:37 by vnastase         ###   ########.fr       */
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
	t_list	list;

	va_start(valist, line);
	character_count = 0;
	while (*line)
	{
		if (*line == '%')
		{
			line++;
			if (*line == 'c')
				ft_case_c(valist, &character_count, list);
			else if (*line == 's')
				ft_case_s(valist, &character_count, list);
			else if (*line == 'p')
				ft_case_p(valist, &character_count, list);
			else if (*line == 'd' || *line == 'i')
				ft_case_id(valist, &character_count, list);
			else if (*line == 'u')
				ft_case_u(valist, &character_count, list);
			else if (*line == 'x')
				ft_case_x(valist, &character_count, list);
			else if (*line == 'X')
				ft_case_mx(valist, &character_count, list);
			else if (*line == '%')
				ft_case_percentage(valist, &character_count, list);
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

void	ft_case_c(va_list valist, int *character_count, t_list list)
{
	list.print_char = va_arg(valist, int);
	ft_putchar(list.print_char);
	(*character_count)++;
}

void	ft_case_s(va_list valist, int *character_count, t_list list)
{
	list.print_string = va_arg(valist, char *);
	ft_put_string(list.print_string);
	*character_count += ft_strlen(list.print_string);
}

void	ft_case_p(va_list valist, int *character_count, t_list list)
{
	char		*print_pointer;
	long int	address;

	list.pointer = (va_arg(valist, void*));
	address = (long int)list.pointer;
	print_pointer = ft_itoa_hex(address, 'W');
	ft_put_string("0x");
	ft_put_string(print_pointer);
	*character_count += ft_strlen(print_pointer);
}

void	ft_case_id(va_list valist, int *character_count, t_list list)
{
	list.print_signed = va_arg(valist, int);
	ft_putnbr_fd(list.print_signed);
	*character_count += ft_count_nb(list.print_signed);
}

void	ft_case_u(va_list valist, int *character_count, t_list list)
{
	list.print_unsigned = va_arg(valist, unsigned int);
	ft_putnbr_fd(list.print_unsigned);
	*character_count += ft_count_nb(list.print_unsigned);
}

void	ft_case_x(va_list valist, int *character_count, t_list list)
{
	char	*num_print;

	list.hexnum = va_arg(valist, int);
	num_print = ft_itoa_hex(list.hexnum, 'W');
	ft_put_string(num_print);
	free(num_print);
	*character_count += ft_strlen(num_print);
}

void	ft_case_mx(va_list valist, int *character_count, t_list list)
{
	char	*num_print;

	list.hexnum = va_arg(valist, int);
	num_print = ft_itoa_hex(list.hexnum, '7');
	ft_put_string(num_print);
	free(num_print);
	*character_count += ft_strlen(num_print);
}

void	ft_case_percentage(va_list valist, int *character_count, t_list list)
{
	ft_putchar('%');
	(*character_count)++;
}

void	ft_last_case(va_list valist, int *character_count)
{
	ft_putchar('%');
	(*character_count)++;
}

int	main(void)
{
	int b = 5;

	ft_printf("%i persona %%  letras\n", b);
	printf("%i persona %%  letras\n", b);
	return 0;
}

