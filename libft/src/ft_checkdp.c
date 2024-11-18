/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:45:27 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/22 18:45:27 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_checkdp(int *numbs, int count)
{
	int	c;
	int	d;

	c = 0;
	while (c < count)
	{
		d = c + 1;
		while (d < count)
		{
			if (numbs[c] == numbs[d])
				return (1);
			d++;
		}
		c++;
	}
	return (0);
}
