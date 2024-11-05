/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:08:50 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/24 14:05:15 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handling(t_data *data)
{
	if (map_component(&data->map) == -1)
	{
		ft_printf("Error\n");
		ft_printf("Number of C,E,P problem or contains\
invalid characters in the map\n");
		light_off (data, 0, 0, 1);
	}
	if (is_rectengular(&data->map) == -1)
	{
		ft_printf("Error\n");
		ft_printf("Map is not rectengular\n");
		light_off (data, 0, 0, 1);
	}
	if (wall_checker(&data->map) == -1)
	{
		ft_printf("Error\n");
		ft_printf("Map is not covered by the wall\n");
		light_off (data, 0, 0, 1);
	}
	return (0);
}

int	function1(int keysym, t_data *data)
{
	if (keysym == KEY_ESC || keysym == DestroyNotify)
	{
		all_free (data);
		light_off (data, 1, 0, 1);
	}
	if (keysym == KEY_W)
		w_movement (data);
	else if (keysym == KEY_S)
		s_movement (data);
	else if (keysym == KEY_A)
		a_movement (data);
	else if (keysym == KEY_D)
		d_movement (data);
	else
		return (0);
	ft_printf ("MOVEMENT:%d\n", data->movement);
	return (0);
}

void	extension_check(char *argv[])
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (argv[1][i] != '\0')
		i ++ ;
	if (argv[1][i - 1] == 'r')
		flag ++ ;
	if (argv[1][i - 2] == 'e')
		flag ++ ;
	if (argv[1][i - 3] == 'b')
		flag ++ ;
	if (argv[1][i - 4] == '.')
		flag ++ ;
	if (flag != 4)
	{
		ft_printf("Error\n");
		ft_printf("Extension Error\n");
		exit (1);
	}
}

int	close_game(t_data *data)
{
	all_free (data);
	light_off (data, 1, 0, 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.movement = 0;
	argc_check(&data, argc, argv);
	extension_check(argv);
	map_initiate(&data.map);
	map_raw_data_maker(&data.map, data.fd);
	map_parser(&data.map);
	error_handling(&data);
	valid_path(&data);
	ft_ptr_init(&data);
	ft_map_init(&data.assets, &data);
	map_maker(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, function1, &data);
	mlx_hook(data.win_ptr, DestroyNotify, ButtonPressMask, close_game, &data);
	mlx_loop(data.mlx_ptr);
}
