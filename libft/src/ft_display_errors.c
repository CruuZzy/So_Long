/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:58:20 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/28 20:58:20 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	malloc_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	null_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	function_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

char	**free_n_exit(void *ptr, int *nums)
{
	if (!ptr)
	{
		if (nums)
		{
			ft_printf("Error\n");
			free(nums);
		}
		return (NULL);
	}
	return (ptr);
}

void	exit_error(void)
{
	exit(EXIT_FAILURE);
}
