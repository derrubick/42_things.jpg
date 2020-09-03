/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:47:52 by vnastase          #+#    #+#             */
/*   Updated: 2020/09/03 19:47:53 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*newlist;

	if (!(newlist = malloc(sizeof(t_list))))
		return (0);
	newlist->content = (void *)content;
	newlist->next = 0;
	return (newlist);
}
