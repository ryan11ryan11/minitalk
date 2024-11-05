/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:13:20 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/27 11:11:12 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(t_data *data, int x, int y)
{
	if (data->splitmap[x][y] == 'E')
		(data->n_e)++;
	if (data->n_c == data->map.num_c && data->n_e == 1)
	{
		data->valid_path = 1;
		return (0);
	}
	if (x >= data->map.height || y >= data->map.width_len || x < 0 || y < 0 || \
		data->splitmap[x][y] == 'E' || data->splitmap[x][y] == '1' || \
			data->ox_plate[x][y] == 1)
		return (0);
	if (data->splitmap[x][y] == 'C')
		(data->n_c)++;
	data->ox_plate[x][y] = 1;
	path_finder(data, x - 1, y);
	path_finder(data, x, y + 1);
	path_finder(data, x + 1, y);
	path_finder(data, x, y - 1);
	return (0);
}

int	ox_plate_maker(t_data *data)
{
	int	i;
	int	height;

	height = 0;
	i = 0;
	data->ox_plate = (char **)malloc(sizeof(char *) * data->map.height);
	while (height < data->map.height)
	{
		data->ox_plate[height] = \
		(char *)ft_calloc(data->map.width_len + 1, sizeof(char));
		height ++ ;
	}
	return (0);
}

void	where_is_p(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->xy = (char *)malloc(3);
	while (data->splitmap[x][y] != 'P')
	{
		if (data->splitmap[x][y] == '\0')
		{
			x ++ ;
			y = 0;
		}
		y ++ ;
	}
	data->xy[0] = x;
	data->xy[1] = y;
	data->xy[2] = '\0';
}

int	valid_path(t_data *data)
{
	data->valid_path = 0;
	data->n_c = 0;
	data->n_e = 0;
	data->splitmap = ft_split(data->map.map_raw_data, '\n');
	ox_plate_maker(data);
	where_is_p(data);
	path_finder(data, data->xy[0], data->xy[1]);
	free(data->xy);
	double_array_free(data->ox_plate, data->map.height);
	double_array_free(data->splitmap, data->map.height);
	if (data->valid_path != 1)
	{
		ft_printf("Error\n");
		ft_printf("Map has no valid path\n");
		free(data->map.map_raw_data);
		exit (1);
	}
	return (0);
}
