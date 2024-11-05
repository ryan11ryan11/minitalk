/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:37:06 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/22 18:35:29 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_component(t_map *map)
{
	if (map->num_c < 1 || map->num_e != 1 || \
			map->num_p != 1 || map->not_allowed_char != 0)
		return (-1);
	return (0);
}

int	wall_checker(t_map *map)
{
	int	ber_line;
	int	i;
	int	k;

	ber_line = 0;
	i = 0;
	k = 0;
	while (map->map_raw_data[i] != '\0')
	{
		if ((ber_line == 0 || ber_line == map->height - 1) \
			&& map->map_raw_data[i] != '1' \
				&& map->map_raw_data[i] != '\n')
			return (-1);
		if ((k == 0 || k == map->width_len - 1) && map->map_raw_data[i] != '1')
			return (-1);
		if (map->map_raw_data[i] == '\n')
		{
			ber_line ++ ;
			k = -1;
		}
		i ++ ;
		k ++ ;
	}
	return (0);
}
