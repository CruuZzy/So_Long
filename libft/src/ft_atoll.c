/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:42:22 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/09/02 19:42:22 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_atoll(const char *str)
{
	long long	c;
	int			sign;
	long long	res;

	c = 0;
	res = 0;
	sign = 1;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\r'
		|| str[c] == '\t' || str[c] == '\v' || str[c] == '\f')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = res * 10 + (str[c] - '0');
		c++;
	}
	return (sign * res);
}
