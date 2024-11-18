/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:14:42 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/01 04:14:42 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strlen_gnl(char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_if_ifind__n(char *s)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_gn(char *s1, char *s2)
{
	int		i;
	int		i2;
	int		len;
	int		j;
	char	*str;

	if (!s1)
		s1 = (char *)ft_calloc_gt(1, sizeof(char));
	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = ft_calloc_gt((len + 1), sizeof(char));
	if (!str || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	i2 = 0;
	while (s2[i2] != '\0')
		str[i++] = s2[i2++];
	free(s1);
	return (str);
}

void	*ft_calloc_gt(size_t tmr, size_t bm)
{
	void			*p;
	int				i;
	unsigned char	*a;
	size_t			size;

	if (tmr == SIZE_MAX || bm == SIZE_MAX)
		return (0);
	p = malloc(tmr * bm);
	if (p == NULL)
		return (NULL);
	i = 0;
	size = tmr * bm;
	if (p)
	{
		a = (unsigned char *) p;
		while (size > 0)
		{
			a[i] = 0;
			i++;
			size--;
		}
	}
	return (p);
}

char	*ft_strdup_gnl(char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	ptr = (char *)malloc(len * (sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i++])
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}