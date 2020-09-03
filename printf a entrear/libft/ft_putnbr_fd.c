/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:49:00 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:49:01 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int				a;
	unsigned int	x;

	if (n < 0)
	{
		write(fd, "-", 1);
		x = n * -1;
	}
	else
		x = n;
	if (x >= 10)
		ft_putnbr_fd(x / 10, fd);
	a = x % 10 + 48;
	write(fd, &a, 1);
}
