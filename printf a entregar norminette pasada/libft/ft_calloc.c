/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:46:15 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:46:16 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libc.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;
	int		count2;

	x = malloc(count * size);
	if (!x)
		return (x);
	count2 = count * size;
	count = 0;
	while (count2--)
	{
		((char*)x)[count] = 0;
		count++;
	}
	return (x);
}
