/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:44:47 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/29 01:51:39 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	str_count(char const *s1, char c)
{
	int	str_c;
	int	str_found;

	str_c = 0;
	str_found = 0;
	if (!s1)
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			str_found = 0;
		else if (str_found == 0)
		{
			str_found = 1;
			str_c++;
		}
		s1++;
	}
	return (str_c);
}

static char	*put_str(char *s1, char c)
{
	int		d;
	int		len;
	char	*array;

	d = 0;
	while (s1[d] && s1[d] != c)
		d++;
	len = d;
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	d = 0;
	while (d < len)
	{
		array[d] = s1[d];
		d++;
	}
	array[len] = '\0';
	return (array);
}

static char	**freemem(char **dst, int d)
{
	while (d > 0)
		free(dst[--d]);
	free(dst);
	return (NULL);
}

static char	**process(char const *s, char c, int word_count)
{
	char	**dst;
	int		d;

	d = 0;
	dst = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!dst)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			dst[d] = put_str((char *)s, c);
			if (!dst[d])
			{
				return (freemem(dst, d));
			}
			d++;
		}
		while (*s && *s != c)
			s++;
	}
	dst[d] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;

	if (!s)
		return (NULL);
	word_count = str_count(s, c);
	return (process(s, c, word_count));
}
