/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:29:57 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/23 18:34:19 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_raw_data_maker(t_map *map, int fd)
{
	char	*file_line;
	char	*tmp;

	tmp = map->map_raw_data;
	file_line = get_next_line(fd);
	while (file_line != NULL)
	{
		tmp = ft_strjoin(map->map_raw_data, file_line);
		free(map->map_raw_data);
		if (tmp == NULL)
		{
			free(file_line);
			return (0);
		}
		map->map_raw_data = tmp;
		free(file_line);
		file_line = get_next_line(fd);
	}
	return (1);
}

void	map_parser(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_raw_data[i] != '\0')
	{
		if (map->map_raw_data[i] == '0' || map->map_raw_data[i] == '1')
		{
		}
		else if (map->map_raw_data[i] == 'E')
			map->num_e ++ ;
		else if (map->map_raw_data[i] == 'C')
			map->num_c ++ ;
		else if (map->map_raw_data[i] == 'P')
			map->num_p ++ ;
		else if (map->map_raw_data[i] == '\n')
			map->height ++ ;
		else
			map->not_allowed_char ++ ;
		i ++ ;
	}
}

int	is_rectengular(t_map *map)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (map->map_raw_data[i] != '\n' && map->map_raw_data[i] != '\0')
		i ++ ;
	map->width_len = i;
	i = 0;
	while (1)
	{
		if (map->map_raw_data[i] == '\n' || map->map_raw_data[i] == '\0')
		{
			if (map->map_raw_data[i] == '\0' && map->width_len == k)
				break ;
			if (map->map_raw_data[i] == '\0' && map->width_len != k)
				return (-1);
			if (map->width_len != k)
				return (-1);
			k = -1;
		}
		k ++ ;
		i ++ ;
	}
	return (1);
}

void	map_initiate(t_map *map)
{
	map->map_raw_data = ft_strdup("");
	map->width_len = 0;
	map->num_c = 0;
	map->num_p = 0;
	map->num_e = 0;
	map->height = 1;
	map->not_allowed_char = 0;
}

int	character_location(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map_raw_data[i] != '\0')
	{
		if (data->map.map_raw_data[i] == 'P')
			return (i);
		i ++ ;
	}
	return (0);
}
