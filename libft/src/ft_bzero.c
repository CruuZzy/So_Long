/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:43:36 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/22 18:38:43 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			c;
	unsigned char	*d;

	d = (unsigned char *)s;
	c = 0;
	if (n == 0)
		return ;
	while (c < n)
	{
		d[c] = 0;
		c++;
	}
}
