/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:03:32 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/22 18:35:54 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cs;
	unsigned char		cc;
	size_t				a;

	cc = (unsigned char )c;
	a = 0;
	cs = (const unsigned char *)s;
	while (a < n)
	{
		if (cs[a] == cc)
			return ((void *)&cs[a]);
		a++;
	}
	return (NULL);
}
