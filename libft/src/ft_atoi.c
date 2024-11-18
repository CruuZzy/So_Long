/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:44:50 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/29 01:52:45 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int					c;
	int					signo;
	int					result;

	c = 0;
	result = 0;
	signo = 1;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\r'
		|| str[c] == '\t' || str[c] == '\v' || str[c] == '\f')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			signo = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		result = result * 10 + (str[c] - '0');
		c++;
	}
	return (signo * result);
}
