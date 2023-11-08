/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:13:04 by gamado-x          #+#    #+#             */
/*   Updated: 2023/11/08 16:20:48 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct	s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		size_len;
	int		endian;
}		t_img;

typedef struct	s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int				color;
}		t_square;

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

t_win	new_program(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);
int	exit_window(t_win *window);
void	draw_square(t_square square, t_img img);

#endif
