/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:14:25 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/21 22:15:35 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*c;

	c = lst;
	if (!c || !lst)
		return (NULL);
	if (!c->next)
		return (c);
	while (c)
	{
		if (!c->next)
			return (c);
		c = c->next;
	}
	return (c);
}
