/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:47:20 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:47:22 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buff1;
	t_list	*buff2;

	buff1 = *lst;
	buff2 = 0;
	while (buff1)
	{
		buff2 = buff1->next;
		del(buff1->content);
		free(buff1);
		buff1 = buff2;
	}
	*lst = 0;
}
