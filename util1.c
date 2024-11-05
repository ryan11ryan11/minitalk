/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:14:08 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/23 13:26:07 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	light_off(t_data *data, int mlx, int win, int raw)
{
	if (mlx > 0)
		free (data->mlx_ptr);
	if (win > 0)
		free (data->win_ptr);
	if (raw > 0)
		free (data->map.map_raw_data);
	exit (1);
}

void	img_free(t_data *data)
{
	mlx_destroy_image (data->mlx_ptr, data->assets.character.img_ptr);
	mlx_destroy_image (data->mlx_ptr, data->assets.collection.img_ptr);
	mlx_destroy_image (data->mlx_ptr, data->assets.exit.img_ptr);
	mlx_destroy_image (data->mlx_ptr, data->assets.tile.img_ptr);
	mlx_destroy_image (data->mlx_ptr, data->assets.wall.img_ptr);
}

int	all_free(t_data *data)
{
	img_free(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	close(data->fd);
	return (0);
}

void	argc_check(t_data *data, int argc, char *argv[])
{
	if (argc <= 1)
	{
		ft_printf("Error\n");
		ft_printf("argc <= 1\n");
		exit (1);
	}
	if (argc > 2)
	{
		ft_printf("Error\n");
		ft_printf("too many argc!\n");
		exit (1);
	}
	data->fd = ft_open(argv[1]);
}

void	double_array_free(char **arr, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free (arr[i]);
		i ++ ;
	}
	free (arr);
}
