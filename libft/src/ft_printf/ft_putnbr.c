/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:12 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/21 22:19:01 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	write_numll(int a)
{
	if (write(1, "-2147483648", 11) == -1)
		return (-1);
	return (a);
}

int	ft_putnbr_long(long n)
{
	int	aux;

	aux = 0;
	if (n == -2147483648)
		return (write_numll(11));
	if (n < 0 && ++aux)
	{
		if (ft_charput('-') == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		aux += ft_putnbr(n / 10);
		if (aux == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_charput(n + '0') == -1)
			return (-1);
		aux++;
	}
	return (aux);
}

int	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (ft_charput('-') == -1)
			return (-1);
		return (ft_putnbr_long(-(long)n) + 1);
	}
	else
		return (ft_putnbr_long(n));
}
