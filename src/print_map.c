/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 07:33:13 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/06 07:33:13 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_data *mlx)
{
	int	img_w;
	int	img_h;

	mlx->player_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player.xpm", &img_w, &img_h);
	mlx->exit_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/house.xpm", &img_w, &img_h);
	mlx->floor_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/floor.xpm", &img_w, &img_h);
	mlx->wall_img[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/bush1.xpm", &img_w, &img_h);
	mlx->wall_img[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/bush2.xpm", &img_w, &img_h);
	mlx->wall_img[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/bush3.xpm", &img_w, &img_h);
	mlx->collectible_img[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/col1.xpm", &img_w, &img_h);
	mlx->collectible_img[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/col2.xpm", &img_w, &img_h);
	mlx->collectible_img[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/col3.xpm", &img_w, &img_h);
	validate_textures(mlx);
}

char	*trim_newline(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	draw_map(t_data *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mlx->map->rows)
	{
		x = -1;
		while (++x < mlx->map->cols)
		{
			draw_map_element(mlx, x, y, mlx->map->map_data[y][x]);
		}
	}
	return (0);
}

int	process_keycode(int keycode, int *new_x, int *new_y, t_data *mlx)
{
	if (keycode == MOVE_W || keycode == 65362)
		(*new_y)--;
	else if (keycode == MOVE_A || keycode == 65361)
		(*new_x)--;
	else if (keycode == MOVE_S || keycode == 65364)
		(*new_y)++;
	else if (keycode == MOVE_D || keycode == 65363)
		(*new_x)++;
	else if (keycode == 65307 || keycode == 53)
	{
		mlx_loop_end(mlx->mlx_ptr);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_data *mlx)
{
	int	new_x;
	int	new_y;

	new_y = mlx->map->player_y;
	new_x = mlx->map->player_x;
	if (process_keycode(keycode, &new_x, &new_y, mlx))
		return (0);
	if (new_x < 0 || new_x >= mlx->map->cols
		|| new_y < 0 || new_y >= mlx->map->rows)
		return (0);
	if (mlx->map->map_data[new_y][new_x] == '1'
		|| (new_x == mlx->map->player_x && new_y == mlx->map->player_y))
		return (0);
	mlx->map->map_data[mlx->map->player_y][mlx->map->player_x] = FLOOR;
	if (!check_player_interaction(mlx, new_x, new_y))
		return (0);
	mlx->map->player_x = new_x;
	mlx->map->player_y = new_y;
	mlx->map->map_data[new_y][new_x] = 'P';
	ft_printf("Movimientos: %d\n", ++mlx->move_count);
	draw_map(mlx);
	return (0);
}
