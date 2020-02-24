/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:40:17 by vnastase          #+#    #+#             */
/*   Updated: 2019/12/16 11:22:36 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
