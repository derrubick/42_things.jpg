/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:46:00 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:46:01 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_atoiresp(char *str, int count, int sign)
{
	long int num;

	num = 0;
	while (str[count] >= '0' && str[count] <= '9')
	{
		num *= 10;
		num += str[count] - 48;
		if ((num * sign) > 2147483647)
			return (-1);
		if ((num * sign) < -2147483648)
			return (0);
		count++;
	}
	return ((int)num * sign);
}

int	ft_atoi(const char *str)
{
	size_t		count;
	int			sign;

	count = 0;
	sign = 1;
	while ((str[count] >= 9 && str[count] <= 13) ||
			str[count] == 32)
		count++;
	if (str[count] == '+')
		count++;
	else if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	return (ft_atoiresp((char*)str, count, sign));
}
