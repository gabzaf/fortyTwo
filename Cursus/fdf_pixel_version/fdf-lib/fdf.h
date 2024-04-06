/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:13:04 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/05 17:41:42 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ESC 65307

typedef struct	s_win
{
	void	*mlx_ptr; 		//Minilib context pointer
	void	*win_ptr;		//Window pointer
	int		height; 	//Height of the matrix
	int		width;  	//Width of the matrix
	float		zoom;
	int		color;
	int		**matrix;	//Matrix
}		t_win;

typedef struct	s_bresenham
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	float	x1;
	float	y1;
	int	max;
	int	z;
	int	z1;
}		t_bresenham;

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

void	file_reader(char *file_name, t_win *window);
void	matrix_insertion(int *matrix_row, char *line);
int	get_width(char *file_name);
int	get_height(char *file_name);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
int	ft_nbr_counter(char const *str, char c);
void	draw(t_win *data);
void	input_error(int argc, char *argv);
void	isometric(float *x, float *y, int z);
int	calculate_color(int z, int z1);
void	screen_fit(float *x, float *x1, float *y, float *y1);

#endif
