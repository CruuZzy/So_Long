/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:04:51 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/15 20:04:51 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_surrounded_by_walls(t_map *map, int x, int y)
{
	return (
		(y > 0 && map->map_data[y - 1][x] == WALL) &&
		(y < map->rows - 1 && map->map_data[y + 1][x] == WALL) &&
		(x > 0 && map->map_data[y][x - 1] == WALL) &&
		(x < map->cols - 1 && map->map_data[y][x + 1] == WALL)
	);
}

int	check_map_surroundings(t_map *map)
{
	int	y;
	int	x;
	int	errors_found;

	errors_found = 0;
	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
			if (map->map_data[y][x] == 'E' || map->map_data[y][x] == 'C'
					|| map->map_data[y][x] == 'P')
			{
				if (is_surrounded_by_walls(map, x, y))
				{
					ft_printf("\nError: '%c' en (%d, %d) está rodeado!",
						map->map_data[y][x], y, x);
					errors_found = 1;
				}
			}
		}
	}
	ft_printf("\n");
	return (errors_found == 0);
}

int	check_exit(t_data *mlx, int new_x, int new_y)
{
	if (mlx->map->map_data[new_y][new_x] == 'E')
	{
		if (mlx->map->collected_items != mlx->map->total_items)
		{
			print_error_so(E20);
			return (0);
		}
		else
		{
			ft_printf("¡Salida encontrada! ¡Felicidades!\n");
			mlx_loop_end(mlx->mlx_ptr);
			return (1);
		}
	}
	return (1);
}

int	check_all_collec(t_data *mlx, int new_x, int new_y)
{
	if (mlx->map->map_data[new_y][new_x] == COLECC)
	{
		mlx->map->collected_items++;
		ft_printf("¡Coleccionable recogido! Total: %d\n",
			mlx->map->collected_items);
	}
	return (1);
}

int	cleanup_and_exit(t_map *map, int exit_code)
{
	if (map)
	{
		free_map_data(map->map_data, map->rows);
		free(map);
	}
	return (exit_code);
}
