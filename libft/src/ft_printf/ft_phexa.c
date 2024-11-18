/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:13:52 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/21 22:19:01 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_decimal_to_hexa(char *bse, unsigned long long i, int c)
{
	unsigned long long	j;

	j = ft_strlenght(bse);
	if (i >= j)
	{
		c = ft_decimal_to_hexa(bse, i / j, c);
		if (c == -1)
			return (-1);
		if (write(1, &bse[i % j], 1) != 1)
			return (-1);
		c++;
	}
	else if (i < j)
	{
		if (write(1, &bse[i], 1) != 1)
			return (-1);
		c++;
	}
	return (c);
}

int	ft_phexa(void *p)
{
	unsigned long long	point;
	int					reg;

	point = (unsigned long long)p;
	reg = 0;
	if (point == 0)
	{
		if (write(1, "0x0", 3) != 3)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) != 2)
		return (-1);
	reg = ft_decimal_to_hexa("0123456789abcdef", point, reg);
	if (reg == -1)
		return (-1);
	reg += 2;
	return (reg);
}
