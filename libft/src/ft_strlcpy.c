/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:56:01 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/22 18:35:54 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	len;

	c = 0;
	len = ft_strlen(src);
	if (src != NULL)
	{
		if (dst != NULL && dstsize > 0)
		{
			while (c < len && c < (dstsize - 1))
			{
				dst[c] = src[c];
				c++;
			}
			dst[c] = '\0';
		}
	}
	return (len);
}
