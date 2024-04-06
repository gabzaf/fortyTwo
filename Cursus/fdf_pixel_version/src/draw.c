/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:24:12 by gamado-x          #+#    #+#             */
/*   Updated: 2023/12/09 17:57:14 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	startp_zoom(float *x, float *y, t_win *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	endp_zoom(float *x1, float *y1, t_win *data)
{
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

void	bresenham(t_bresenham bre, t_win *data)
{
	bre.z = data->matrix[(int)bre.y][(int)bre.x];
	bre.z1 = data->matrix[(int)bre.y1][(int)bre.x1];
	startp_zoom(&bre.x, &bre.y, data);
	endp_zoom(&bre.x1, &bre.y1, data);
	data->color = calculate_color(bre.z, bre.z1);
	isometric(&bre.x, &bre.y, bre.z);
	isometric(&bre.x1, &bre.y1, bre.z1);
	screen_fit(&bre.x, &bre.x1, &bre.y, &bre.y1);
	bre.x_step = bre.x1 - bre.x;
	bre.y_step = bre.y1 - bre.y;
	bre.max = fmax(fabs(bre.x_step), fabs(bre.y_step));
	bre.x_step /= bre.max;
	bre.y_step /= bre.max;
	while ((int)(bre.x - bre.x1) || (int)(bre.y - bre.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, bre.x, bre.y, data->color);
		bre.x += bre.x_step;
		bre.y += bre.y_step;
	}
}

void	grid_lines(float *x, float *y, t_bresenham *bre, t_win *data)
{
	bre->x = *x;
	bre->y = *y;
	if (*x < data->width - 1)
	{
		bre->x1 = *x + 1;
		bre->y1 = *y;
		bresenham(*bre, data);
	}
	if (*y < data->height -1)
	{
		bre->x1 = *x;
		bre->y1 = *y + 1;
		bresenham(*bre, data);
	}
}

void	draw(t_win *data)
{
	t_bresenham	*bre;
	float		x;
	float		y;

	bre = NULL;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			bre = (t_bresenham *)malloc(sizeof(t_bresenham));
			if (!bre)
				exit(0);
			grid_lines(&x, &y, bre, data);
			free(bre);
			x++;
		}
		y++;
	}
}
