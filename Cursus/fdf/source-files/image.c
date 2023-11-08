/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:37:42 by gamado-x          #+#    #+#             */
/*   Updated: 2023/11/08 11:58:21 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.size_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}
