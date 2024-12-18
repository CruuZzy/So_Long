/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 05:15:43 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/07 05:15:43 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	initialize_mlx(t_data *mlx, t_map *map)
{
	int	window_w;
	int	window_h;

	window_w = map->cols * 32;
	window_h = map->rows * 32;
	mlx->move_count = 0;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		ft_printf("Error: No se pudo inicializar mlx.\n");
		return (1);
	}
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, window_w, window_h, "So Long");
	if (!mlx->mlx_win)
	{
		ft_printf("Error: No se pudo crear la ventana.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (1);
	}
	return (0);
}

int	initialize_map(int argc, char *argv[], t_map **map)
{
	if (argc != 2)
	{
		ft_printf("Uso: %s <ruta_del_mapa>\n", argv[0]);
		return (1);
	}
	if (!check_map_ber(argv[1]))
	{
		ft_printf("Error: El archivo debe tener la extensión .ber\n");
		return (1);
	}
	*map = read_map(argv[1]);
	if (!(*map))
		print_error_so(E14);
	return (*map == NULL);
}

t_map	*initialize_map_struct(int fd)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		print_error_so(E19);
		close(fd);
		return (NULL);
	}
	map->rows = 0;
	map->cols = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->collected_items = 0;
	map->total_items = 0;
	return (map);
}

int	load_and_verify_textures(t_data *mlx)
{
	load_textures(mlx);
	if (!mlx->floor_img || !mlx->wall_img
		|| !mlx->collectible_img || !mlx->player_img)
	{
		ft_printf("Error: Alguna de las texturas no se cargó correctamente.\n");
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (1);
	}
	return (0);
}
