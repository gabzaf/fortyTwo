/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:41:23 by gamado-x          #+#    #+#             */
/*   Updated: 2023/12/07 19:20:38 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_win *win)
{
	if (win)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		free(win->mlx_ptr);
		free(win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	deal_key(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == ESC)
		close_window(win);
	return (0);
}

void	new_window(t_win *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	if (!data->mlx_ptr || !data->win_ptr)
		exit(0);
}

int	main(int argc, char **argv)
{
	t_win	*data;

	input_error(argc, argv[1]);
	data = (t_win *)malloc(sizeof(t_win));
	if (!data)
		exit(0);
	file_reader(argv[1], data);
	new_window(data);
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, &deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
