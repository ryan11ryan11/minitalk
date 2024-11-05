/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:39:28 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/21 17:06:23 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("can not open the file\n");
		exit (1);
	}
	return (fd);
}

void	ft_ptr_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->map.width_len * 64, data->map.height * 64, "so_long");
	if (data->mlx_ptr == 0)
	{
		ft_printf("Fail to mlx_init\n");
		exit (1);
	}
	if (data->win_ptr == 0)
	{
		ft_printf("Fail to mlx_new_window\n");
		light_off (data, 1, 0, 1);
	}
}

void	ft_map_init(t_assets *assets, t_data *data)
{
	if (map_init(assets, data) == -1)
	{
		ft_printf("Error at map_init");
		light_off (data, 1, 1, 1);
	}
}
