/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:41:23 by gamado-x          #+#    #+#             */
/*   Updated: 2023/11/08 16:28:37 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(void)
{
	t_win	make_window;
	t_img	img;

	make_window = new_program(300, 300, "42FDF");
	if (!make_window.mlx_ptr || !make_window.win_ptr)
		return (1);
	img = new_img(300, 300, make_window);
	//memcpy(img.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
	put_pixel_img(img, 150, 150, 0x00FFFFFF);
	draw_square((t_square){0, 0, 300, 0x00FF00}, img);
	mlx_put_image_to_window(img.win.mlx_ptr, img.win.win_ptr, img.img_ptr, 0, 0);
	/*printf("Let's Find out what's inside our structure :D\n");
	printf("img_ptr		: [%p]\n", img.img_ptr);
	printf("bpp		: [%d]\n", img.bpp);
	printf("line_len	: [%d]\n", img.size_len);
	printf("endian		: [%d]\n", img.endian);
	printf("addr		: [%p]\n", img.addr);*/
	mlx_hook(make_window.win_ptr, 17, 0, exit_window, &make_window);
	mlx_loop(make_window.mlx_ptr);
	return (0);
}
