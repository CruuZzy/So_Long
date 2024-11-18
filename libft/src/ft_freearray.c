/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:18:13 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/07/25 22:18:13 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_freearray(char **array)
{
	size_t	c;

	c = 0;
	if (array)
	{
		while (array && array[c])
		{
			if (array[c] != NULL)
			{
				free(array[c]);
				array[c] = NULL;
			}
			c++;
		}
		free(array);
		array = NULL;
	}
}
