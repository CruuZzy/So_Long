/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:00:38 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/01 00:00:38 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_shape(t_map *map)
{
	int	i;
	int	len;

	i = -1;
	while (++i < map->rows)
	{
		len = ft_strlen(map->map_data[i]);
		ft_printf("Fila %d: %s", i, map->map_data[i]);
		if (map->map_data[i][len - 1] == '\n')
			len--;
		if (len != map->cols)
		{
			print_error_so(E16);
			return (0);
		}
	}
	return (1);
}

int	check_map_borders(t_map *map)
{
	int	i;

	i = -1;
	if (map->cols <= 0 || map->rows <= 0)
		print_error_so(E11);
	while (++i < map->cols)
	{
		if (map->map_data[0][i] != '1' || map->map_data[map->rows -1][i] != '1')
			print_error_so(E11);
	}
	i = -1;
	while (++i < map->rows)
	{
		if (map->map_data[i][0] != '1' || map->map_data[i][map->cols -1] != '1')
			print_error_so(E12);
	}
	return (1);
}

int	check_map_elements(t_map *map)
{
	int	player_count;
	int	collectible_count;
	int	exit_count;
	int	c;
	int	d;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	c = -1;
	while (++c < map->rows)
	{
		d = -1;
		while (++d < map->cols)
			process_map_char(map->map_data[c][d], &player_count,
				&exit_count, &collectible_count);
	}
	if (player_count != 1)
		print_error_so(E13);
	if (exit_count == 0 || collectible_count == 0)
		print_error_so(E15);
	if (collectible_count == 0)
		print_error_so(E10);
	return (1);
}

int	validate_map(t_map *map)
{
	if (!check_map_shape(map))
		return (0);
	if (!check_map_borders(map))
		return (0);
	if (!check_map_elements(map))
		return (0);
	if (!check_map_surroundings(map))
		return (0);
	return (1);
}

int	check_map_ber(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}
