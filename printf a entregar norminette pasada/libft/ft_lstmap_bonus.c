/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:47:47 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:47:48 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*rst;

	if (!lst)
		return (0);
	if (!(new = ft_lstnew(f(lst->content))))
		del(lst);
	lst = lst->next;
	rst = new;
	while (lst)
	{
		if (!(new->next = ft_lstnew(f(lst->content))))
			del(lst);
		lst = lst->next;
		new = new->next;
	}
	return (rst);
}
