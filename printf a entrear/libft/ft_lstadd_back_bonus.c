/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:47:05 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:47:07 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*buff;

	if (!alst)
		return ;
	buff = *alst;
	if (*alst == 0)
		*alst = new;
	else
	{
		while ((*buff).next)
			buff = (*buff).next;
		(*buff).next = new;
	}
}
