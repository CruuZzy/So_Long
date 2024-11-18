/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:46:52 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/22 18:35:54 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*ps1;
	char		*c;
	size_t		a;
	size_t		len;

	a = 0;
	ps1 = (char *)s1;
	len = ft_strlen(ps1) + 1;
	c = (char *)malloc(len);
	if (!c)
		return (NULL);
	while (ps1[a] != '\0')
	{
		c[a] = ps1[a];
		a++;
	}
	c[a] = '\0';
	return (c);
}
