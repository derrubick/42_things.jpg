/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:23:42 by vnastase          #+#    #+#             */
/*   Updated: 2019/12/10 12:30:13 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*ptr;
	void	*contenido;

	contenido = (void *)content;
	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = contenido;
	ptr->next = NULL;
	return (ptr);
}
