/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:49:42 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/09/25 01:49:42 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <X11/keysym.h>

# define INITIAL_CAPACITY 10
# define HEIGHT  600
# define WIDTH  600 
# define MOVE_W 119
# define MOVE_A 97
# define MOVE_S 115
# define MOVE_D 100
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLECC 'C'
# define EXIT 'E'

typedef struct s_map
{
	char	**map_data;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collected_items;
	int		total_items;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*win;
	void	*floor_img;
	void	*wall_img[3];
	void	*player_img;
	void	*collectible_img[3];
	void	*exit_img;
	t_map	*map;
	int		move_count;
}	t_data;

typedef enum e_error_code
{
	E10,
	E11,
	E12,
	E13,
	E14,
	E15,
	E16,
	E17,
	E18,
	E19,
	E20,
	E21,
	E22,
	UNKNOWN_ERROR
}	t_error_code;

int		check_map_shape(t_map *map);
int		check_map_borders(t_map *map);
int		check_map_elements(t_map *map);
int		validate_map(t_map *map);
int		check_map_ber(const char *filename);
int		handle_close(t_data *mlx);
int		render_next_frame(void *param);
int		print_error_so(t_error_code code);
int		key_hook(int keycode, t_data *mlx);
int		initialize_mlx(t_data *mlx, t_map *map);
int		draw_map(t_data *mlx);
int		expand_map_data(char ***map_data, int *capacity);
int		initialize_map(int argc, char *argv[], t_map **map);
int		load_and_verify_textures(t_data *mlx);
int		open_map_file(const char *filename);
int		process_keycode(int keycode, int *new_x, int *new_y, t_data *mlx);
void	free_map_data(char **map_data, int rows);
void	load_textures(t_data *mlx);
void	setup_hooks_and_loop(t_data *mlx);
void	cleanup(t_data *mlx, t_map *map);
void	process_line(char *line, t_map *map);
char	**allocate_map_data(int *capacity);
char	*trim_newline(char *line);
t_map	*initialize_map_struct(int fd);
t_map	*read_map(const char *filename);
t_map	*finalize_map_reading(int fd, t_map *map, char **map_data);
t_map	*handle_map_data_error(t_map *map, int fd);
t_map	*handle_expand_error(char **map_data, t_map *map, int fd, int rows);
int		is_surrounded_by_walls(t_map *map, int x, int y);
int		check_map_surroundings(t_map *map);
int		check_exit(t_data *mlx, int new_x, int new_y);
int		check_all_collec(t_data *mlx, int new_x, int new_y);
int		check_player_interaction(t_data *mlx, int new_x, int new_y);
int		validate_textures(t_data *mlx);
int		cleanup_and_exit(t_map *map, int exit_code);
void	process_map_char(char map_char, int *player_count,
			int *exit_count, int *collectible_count);
void	draw_map_element(t_data *mlx, int x, int y, char element);
void	flood_fill(t_map *map, int x, int y, char **visited);
char	**copy_map(char **map_data, int rows);
int		check_accessibility(t_map *map);
int		check_map_accessibility(t_map *map);
void	free_visited(char **visited, int rows);

#endif
