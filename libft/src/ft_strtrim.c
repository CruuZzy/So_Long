/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:20:06 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/22 18:35:54 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_char_true(char c, char const *set)
{
	size_t	a;

	a = 0;
	while (set[a] != '\0')
	{
		if (set[a] == c)
		{
			return (1);
		}
		a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	d;
	char	*str;

	d = 0;
	start = 0;
	len = ft_strlen(s1);
	end = len;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_char_true(s1[start], set))
		start++;
	while (end > start && ft_char_true(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
		str[d++] = s1[start++];
	str[d] = '\0';
	return (str);
}
