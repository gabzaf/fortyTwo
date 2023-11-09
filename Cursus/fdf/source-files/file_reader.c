/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:53:23 by gamado-x          #+#    #+#             */
/*   Updated: 2023/11/09 18:55:52 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	get_height()
{
	int	height;
	int	fd;

	fd = open("/nfs/homes/gamado-x/Documents/Cursus/fdf/test_maps/42.fdf", O_RDONLY);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	if (height == 0)
		exit(0);
	return (height);
}

int	get_width(int height)
{
	int	width;
	int	i;
	int	fd;

	fd = open("/nfs/homes/gamado-x/Documents/Cursus/fdf/test_maps/42.fdf", O_RDONLY);
	i = 0;
	width = ft_strlen(get_next_line(fd));
	while (i < height - 1)
	{
		if (width != ft_strlen(get_next_line(fd)))
		{
			printf("Wrong format map.");
			exit(0);
		}
		i++;
	}
	close(fd);
	return (width);
}

void	matrix_insertion(int **m, int r, int c)
{
	int	i;

	i = 0;
	while (i < r)
	{
		m[i] = (int *)malloc(c * sizeof(int));
		
		i++;
	}
}

int	main(void)
{
	int	fd;
	int	rows;
	int	cols;
	int	**matrix;

	rows = get_height();
	printf("%d", rows);
	matrix = (int **)malloc(rows * sizeof(int *));
	cols = get_width(rows);

	printf("%d", cols);
	free(matrix);
	return (0);
}
