/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:38:32 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/21 22:19:01 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned int	ft_num_unsign(unsigned int num)
{
	int	aux;

	aux = 0;
	if (num <= 9)
	{
		if (ft_charput(num + '0') == -1)
			return (-1);
		aux++;
	}
	else
	{
		aux = ft_num_unsign(num / 10);
		if (aux == -1)
			return (-1);
		if (ft_charput(num % 10 + '0') == -1)
			return (-1);
		aux++;
	}
	return (aux);
}
