/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:48:54 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:48:55 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		ft_duplicate(char *base, int nbr, int i, int b)
{
	while (base[i] != '\0')
	{
		if (base[i] == base[b])
			return (0);
		i++;
	}
	b++;
	i = b++;
	if (b <= nbr)
		ft_duplicate(base, ft_strlen(base), i, b);
	return (1);
}

void			ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int				a;
	unsigned int	x;
	unsigned int	len;

	len = ft_strlen(base);
	if (len == 0 || len < 2
	|| ft_duplicate(base, len, 1, 0) == 0)
		return ;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		x = nbr * -1;
	}
	else
		x = nbr;
	if (x >= len)
		ft_putnbr_base_fd(x / len, base, fd);
	a = base[nbr % len];
	write(fd, &a, 1);
}
