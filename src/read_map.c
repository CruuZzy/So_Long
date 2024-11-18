/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:47:52 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/01 00:47:52 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error_so(E18);
	return (fd);
}

char	**allocate_map_data(int *capacity)
{
	*capacity = INITIAL_CAPACITY;
	return (malloc(sizeof(char *) * (*capacity)));
}

int	expand_map_data(char ***map_data, int *capacity)
{
	int		new_capacity;
	char	**temp;
	int		i;

	new_capacity = (*capacity) * 2;
	temp = malloc(sizeof(char *) * new_capacity);
	if (!temp)
		return (0);
	i = -1;
	while (++i < *capacity)
		temp[i] = (*map_data)[i];
	free(*map_data);
	*map_data = temp;
	*capacity = new_capacity;
	return (1);
}

void	free_map_data(char **map_data, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free(map_data[i]);
	free(map_data);
}

t_map	*read_map(const char *filename)
{
	t_map	*map;
	char	**map_data;
	char	*line;
	int		fd;
	int		capacity;

	fd = open_map_file(filename);
	map = initialize_map_struct();
	if (!map)
		return (close(fd), NULL);
	map_data = allocate_map_data(&capacity);
	if (!map_data)
		return (handle_map_data_error(map, fd));
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_line(line, map);
		if (map->rows > capacity)
			if (!expand_map_data(&map_data, &capacity))
				return (handle_expand_error(map_data, map, fd, map->rows));
		map_data[map->rows - 1] = line;
		line = get_next_line(fd);
	}
	close(fd);
	return (finalize_map_reading(fd, map, map_data));
}
