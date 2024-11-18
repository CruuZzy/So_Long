/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:08:02 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/22 18:35:54 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	digits(int n)
{
	int	c;
	int	aux;

	c = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		c++;
	}
	aux = n;
	while (aux > 0)
	{
		aux = aux / 10;
		c++;
	}
	return (c);
}

int	exp_c(int n)
{
	int	exp;
	int	dig;

	exp = 1;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (1000000000LL);
	dig = digits(n);
	if (n < 0)
		dig--;
	while (--dig)
	{
		exp = exp * 10;
	}
	return (exp);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			c;
	int			exp;
	long int	aux;

	aux = (long int)n;
	exp = exp_c(n);
	c = 0;
	str = malloc(digits(n) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[c++] = '-';
		aux = -aux;
	}
	while (exp > 0)
	{
		str[c++] = (aux / exp) + '0';
		aux = aux % exp;
		exp = exp / 10;
	}
	str[c] = '\0';
	return (str);
}
