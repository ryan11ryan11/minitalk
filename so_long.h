/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:11:14 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/27 10:57:55 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# define WALL_PATH "imagefiles/wall.xpm"
# define GRASS_PATH "imagefiles/grass.xpm"
# define EXIT_PATH "imagefiles/exit.xpm"
# define COLLECTION_PATH "imagefiles/collection.xpm"
# define CHARACTER_PATH "imagefiles/character.xpm"
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_UP				65362
# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_DOWN			65364
# define KEY_Q				113
# define KEY_ESC			65307

typedef struct s_map
{
	char	*map_raw_data;
	int		num_e;
	int		num_c;
	int		num_p;
	int		width_len;
	int		height;
	int		not_allowed_char;
}	t_map;

typedef struct s_img
{
	int		x;
	int		y;
	void	*img_ptr;
}	t_img;

typedef struct s_assets
{
	t_img	character;
	t_img	tile;
	t_img	wall;
	t_img	collection;
	t_img	exit;
}	t_assets;

typedef struct s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	char		**splitmap;
	char		**ox_plate;
	char		*xy;
	int			valid_path;
	int			movement;
	int			fd;
	int			n_c;
	int			n_e;
	t_map		map;
	t_assets	assets;
}	t_data;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

int		map_raw_data_maker(t_map *map, int fd);
void	map_parser(t_map *map);
int		is_rectengular(t_map *map);
void	map_initiate(t_map *map);
int		ft_printf(const char *contentptr, ...);

int		map_component(t_map *map);
int		wall_checker(t_map *map);

int		map_init(t_assets *assets, t_data *data);
void	build_map(t_data *data, int x, int y);
int		map_maker(t_data *data);

void	light_off(t_data *data, int mlx, int win, int raw);

int		ft_open(char *file_name);
void	ft_ptr_init(t_data *data);
void	ft_map_init(t_assets *assets, t_data *data);

int		character_location(t_data *data);
int		w_movement(t_data *data);
int		a_movement(t_data *data);
int		s_movement(t_data *data);
int		d_movement(t_data *data);

int		all_free(t_data *data);
void	light_off(t_data *data, int mlx, int win, int raw);
void	img_free(t_data *data);
void	argc_check(t_data *data, int argc, char *argv[]);

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);

int		valid_path(t_data *data);
void	where_is_p(t_data *data);
int		ox_plate_maker(t_data *data);
void	double_array_free(char **arr, int k);
int		path_finder(t_data *data, int x, int y);
void	build_map2(t_data *data, int x, int y, char type);

#endif
