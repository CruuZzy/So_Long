/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:30:14 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/01 04:30:14 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*handle_map_data_error(t_map *map, int fd)
{
	free(map);
	close(fd);
	return (NULL);
}

t_map	*handle_expand_error(char **map_data, t_map *map, int fd, int rows)
{
	free_map_data(map_data, rows - 1);
	free(map);
	close(fd);
	return (NULL);
}

int	check_player_interaction(t_data *mlx, int new_x, int new_y)
{
	if (!check_all_collec(mlx, new_x, new_y))
		return (0);
	if (!check_exit(mlx, new_x, new_y))
		return (0);
	return (1);
}

int	validate_textures(t_data *mlx)
{
	if (!mlx->floor_img || !mlx->wall_img[0]
		|| !mlx->wall_img[1] || !mlx->wall_img[2]
		|| !mlx->player_img || !mlx->collectible_img[0]
		|| !mlx->collectible_img[1]
		|| !mlx->collectible_img[2] || !mlx->exit_img)
	{
		ft_printf("Error: Faltan texturas\n");
		return (0);
	}
	ft_printf("\nTexturas cargadas correctamente.\n");
	return (1);
}

int	print_error_so(t_error_code code)
{
	const char	*error_messages[] = {
	[E10] = "\nError: Debe haber al menos un coleccionable en el mapa.\n",
	[E11] = "\nError: bordes superior o inferior no están rodeados de muros.\n",
	[E12] = "Error: los bordes izquierdo o derecho no están rodeados de muros.",
	[E13] = "\nError: Debe haber solo 1 jugador y 1 salida en el mapa.\n",
	[E14] = "\nNo se pudo leer el mapa.\n",
	[E15] = "\nDebe tener al menos 1 salida el mapa.",
	[E16] = "Error: El mapa no es rectangular.",
	[E17] = "\nError: Caracter no válido en el mapa.",
	[E18] = "\nError al abrir el archivo.",
	[E19] = "\nError de memoria.",
	[E20] = "\n¡Debes recoger todos los coleccionables antes de salir!\n",
	[E21] = "\n!ERROR MAS DE 1 PLAYER!\n",
	[E22] = "\nAlgun coleccionable, salida o jugador estan bloqueados\n",	
	[UNKNOWN_ERROR] = "\nError desconocido.\n"
	};

	if (code >= 0 && code <= UNKNOWN_ERROR)
	{
		ft_printf("%s\n", error_messages[code]);
		return (0);
	}
	ft_printf("Error desconocido.\n");
	return (0);
}
