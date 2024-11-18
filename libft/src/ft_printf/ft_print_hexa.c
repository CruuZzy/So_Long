/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:31:48 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/21 22:19:01 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static int	ft_put_hexa(unsigned int n, const char pformat)
{
	if (n >= 16)
	{
		if (ft_put_hexa(n / 16, pformat) == -1)
			return (-1);
		if (ft_put_hexa(n % 16, pformat) == -1)
			return (-1);
	}
	else
	{
		if (n <= 9)
		{
			if (ft_charput(n + '0') == -1)
				return (-1);
		}
		else
		{
			if (pformat == 'x')
				if (ft_charput(n - 10 + 'a') == -1)
					return (-1);
			if (pformat == 'X')
				if (ft_charput(n - 10 + 'A') == -1)
					return (-1);
		}
	}
	return (0);
}

int	ft_print_hexa(unsigned int n, const char pformat)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		if (ft_put_hexa(n, pformat) == -1)
			return (-1);
	return (ft_hexa_len(n));
}
