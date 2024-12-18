/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:13:56 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/12/18 18:26:16 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_map *map, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= map->cols || y >= map->rows)
		return ;
	if (visited[y][x] == '1' || visited[y][x] == 'V')
		return ;
	visited[y][x] = 'V';
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
}

char	**copy_map(char **map_data, int rows)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * rows);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(map_data[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

int	check_accessibility(t_map *map)
{
	char	**visited;
	int		i;
	int		j;

	visited = malloc(sizeof(char *) * map->rows);
	if (!visited)
		return (0);
	i = -1;
	while (++i < map->rows)
		visited[i] = ft_strdup(map->map_data[i]);
	flood_fill(map, map->player_x, map->player_y, visited);
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if ((map->map_data[i][j] == 'C' || map->map_data[i][j] == 'E')
				&& visited[i][j] != 'V')
				return (free_visited(visited, map->rows), 0);
		}
	}
	free_visited(visited, map->rows);
	return (1);
}

void	free_visited(char **visited, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free(visited[i]);
	free(visited);
}

int	check_map_accessibility(t_map *map)
{
	char	**copy;

	copy = copy_map(map->map_data, map->rows);
	if (!copy)
		return (print_error_so(E21), 0);
	flood_fill(map, map->player_x, map->player_y, copy);
	if (!check_accessibility(map))
	{
		free_map_data(copy, map->rows);
		return (print_error_so(E22), 0);
	}
	free_map_data(copy, map->rows);
	return (1);
}
