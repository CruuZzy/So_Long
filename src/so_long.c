/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:48:23 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/09/25 01:48:23 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_close(t_data *mlx)
{
	ft_printf("Juego cerrado.\n");
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free_map_data(mlx->map->map_data, mlx->map->rows);
	free(mlx->map);
	exit(0);
}

void	setup_hooks_and_loop(t_data *mlx)
{
	mlx_hook(mlx->mlx_win, 17, 0, handle_close, mlx);
	mlx_loop_hook(mlx->mlx_ptr, draw_map_hook, mlx);
	mlx_key_hook(mlx->mlx_win, key_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	cleanup(t_data *mlx, t_map *map)
{
	free_map_data(map->map_data, map->rows);
	free(map);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_data	mlx;

	if (initialize_map(argc, argv, &map))
		return (1);
	if (!validate_map(map))
		return (cleanup_and_exit(map, 1));
	if (initialize_mlx(&mlx, map))
		return (cleanup_and_exit(map, 1));
	mlx.map = map;
	mlx.map->map_data[mlx.map->player_y][mlx.map->player_x] = 'P';
	if (load_and_verify_textures(&mlx))
		return (cleanup_and_exit(map, 1));
	setup_hooks_and_loop(&mlx);
	cleanup(&mlx, map);
	return (0);
}
