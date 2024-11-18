/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:32:01 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/21 22:15:35 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*addinf;
	t_list	*new;
	void	*set;

	if (!f || !del || !lst)
		return (NULL);
	new = NULL;
	while (lst)
	{
		set = f(lst->content);
		addinf = ft_lstnew(set);
		if (!addinf)
		{
			del(set);
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, addinf);
		lst = lst->next;
	}
	return (new);
}
