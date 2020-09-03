/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:47:56 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:47:57 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int			i;

	i = 0;
	while (lst)
	{
		lst = (*lst).next;
		i++;
	}
	return (i);
}
