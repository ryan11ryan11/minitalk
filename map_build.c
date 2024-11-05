/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:41:26 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/23 16:23:36 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_assets *assets, t_data *data)
{
	assets->character.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		CHARACTER_PATH, &assets->character.x, &assets->character.y);
	assets->tile.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		GRASS_PATH, &assets->tile.x, &assets->tile.y);
	assets->wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		WALL_PATH, &assets->wall.x, &assets->wall.y);
	assets->collection.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		COLLECTION_PATH, &assets->collection.x, &assets->collection.y);
	assets->exit.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		EXIT_PATH, &assets->exit.x, &assets->exit.y);
	if (assets->character.img_ptr == 0)
		return (-1);
	if (assets->tile.img_ptr == 0)
		return (-1);
	if (assets->wall.img_ptr == 0)
		return (-1);
	if (assets->collection.img_ptr == 0)
		return (-1);
	if (assets->exit.img_ptr == 0)
		return (-1);
	return (1);
}

void	build_map2(t_data *data, int x, int y, char type)
{
	if (type == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->assets.tile.img_ptr, x, y);
	if (type == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->assets.wall.img_ptr, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->assets.exit.img_ptr, x, y);
	else if (type == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->assets.collection.img_ptr, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->assets.character.img_ptr, x, y);
}

void	build_map(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (data->map.map_raw_data[i] != '\0')
	{
		if (data->map.map_raw_data[i] == '0')
			build_map2(data, x, y, '0');
		if (data->map.map_raw_data[i] == '1')
			build_map2(data, x, y, '1');
		else if (data->map.map_raw_data[i] == 'E')
			build_map2(data, x, y, 'E');
		else if (data->map.map_raw_data[i] == 'C')
			build_map2(data, x, y, 'C');
		else if (data->map.map_raw_data[i] == 'P')
			build_map2(data, x, y, 'P');
		else if (data->map.map_raw_data[i] == '\n')
		{
			y = y + 64;
			x = -64;
		}
		i ++ ;
		x = x + 64;
	}
}

int	map_maker(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	build_map (data, x, y);
	return (1);
}
