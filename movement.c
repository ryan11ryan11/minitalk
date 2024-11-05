/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:26:57 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/22 18:38:54 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enter_exit(t_data *data, int wanted_location)
{
	map_maker(data);
	if (data->map.map_raw_data[wanted_location] == 'E' && data->map.num_c == 0)
	{
		ft_printf("GAME FINISHED, WELL DONE, MOVEMENT:%d\n", data->movement);
		all_free (data);
		light_off(data, 1, 0, 1);
	}
}

int	w_movement(t_data *data)
{
	int	current_location;
	int	wanted_location;

	current_location = character_location(data);
	wanted_location = character_location(data) - data->map.width_len - 1;
	if (data->map.map_raw_data[wanted_location] == '1' || \
		(data->map.map_raw_data[wanted_location] == 'E' \
			&& data->map.num_c != 0))
		return (0);
	if (data->map.map_raw_data[wanted_location] == '0' || \
			data->map.map_raw_data[wanted_location] == 'C')
	{
		if (data->map.map_raw_data[wanted_location] == 'C')
			data->map.num_c -- ;
		data->map.map_raw_data[current_location] = '0';
		data->map.map_raw_data[wanted_location] = 'P';
	}
	data->movement ++ ;
	enter_exit(data, wanted_location);
	return (0);
}

int	d_movement(t_data *data)
{
	int	current_location;
	int	wanted_location;

	current_location = character_location(data);
	wanted_location = character_location(data) + 1;
	if (data->map.map_raw_data[wanted_location] == '1' || \
		(data->map.map_raw_data[wanted_location] \
			== 'E' && data->map.num_c != 0))
		return (0);
	if (data->map.map_raw_data[wanted_location] == '0' || \
			data->map.map_raw_data[wanted_location] == 'C')
	{
		if (data->map.map_raw_data[wanted_location] == 'C')
			data->map.num_c -- ;
		data->map.map_raw_data[current_location] = '0';
		data->map.map_raw_data[wanted_location] = 'P';
	}
	data->movement ++ ;
	enter_exit(data, wanted_location);
	return (0);
}

int	a_movement(t_data *data)
{
	int	current_location;
	int	wanted_location;

	current_location = character_location(data);
	wanted_location = character_location(data) - 1;
	if (data->map.map_raw_data[wanted_location] == '1' || \
		(data->map.map_raw_data[wanted_location] == 'E' \
			&& data->map.num_c != 0))
		return (0);
	if (data->map.map_raw_data[wanted_location] == '0' || \
			data->map.map_raw_data[wanted_location] == 'C')
	{
		if (data->map.map_raw_data[wanted_location] == 'C')
			data->map.num_c -- ;
		data->map.map_raw_data[current_location] = '0';
		data->map.map_raw_data[wanted_location] = 'P';
	}
	data->movement ++ ;
	enter_exit(data, wanted_location);
	return (0);
}

int	s_movement(t_data *data)
{
	int	current_location;
	int	wanted_location;

	current_location = character_location(data);
	wanted_location = character_location(data) + data->map.width_len + 1;
	if (data->map.map_raw_data[wanted_location] == '1' || \
		(data->map.map_raw_data[wanted_location] == 'E'\
			&& data->map.num_c != 0))
		return (0);
	if (data->map.map_raw_data[wanted_location] == '0' || \
			data->map.map_raw_data[wanted_location] == 'C')
	{
		if (data->map.map_raw_data[wanted_location] == 'C')
			data->map.num_c -- ;
		data->map.map_raw_data[current_location] = '0';
		data->map.map_raw_data[wanted_location] = 'P';
	}
	data->movement ++ ;
	enter_exit(data, wanted_location);
	return (0);
}
