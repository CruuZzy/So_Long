/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 05:31:44 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/07 05:31:44 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	process_line(char *line, t_map *map)
{
	int	i;

	if (*line == '\0')
	{
		free(line);
		return ;
	}
	map->rows++;
	if (map->cols == 0)
		map->cols = ft_strlen(line) - 1;
	i = -1;
	while (++i < map->cols)
	{
		if (line[i] == 'P')
		{
			map->player_x = i;
			map->player_y = map->rows - 1;
		}
		if (line[i] == 'C')
			map->total_items++;
	}
}

t_map	*finalize_map_reading(int fd, t_map *map, char **map_data)
{
	close(fd);
	map->map_data = map_data;
	return (map);
}

void	process_map_char(char map_char, int *player_count,
				int *exit_count, int *collectible_count)
{
	if (map_char == 'P')
		(*player_count)++;
	else if (map_char == 'E')
		(*exit_count)++;
	else if (map_char == 'C')
		(*collectible_count)++;
	else if (map_char != '1' && map_char != '0')
		print_error_so(E17);
}

void	draw_map_element(t_data *mlx, int x, int y, char element)
{
	int	type;

	if (element == '1')
	{
		type = (x + y) % 3;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->wall_img[type], x * 32, y * 32);
	}
	else if (element == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->floor_img, x * 32, y * 32);
	else if (element == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->player_img, x * 32, y * 32);
	else if (element == 'C')
	{
		type = (x + y) % 3;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->collectible_img[type], x * 32, y * 32);
	}
	else if (element == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->exit_img, x * 32, y * 32);
}
