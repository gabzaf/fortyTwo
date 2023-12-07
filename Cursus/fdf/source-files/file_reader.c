/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:53:23 by gamado-x          #+#    #+#             */
/*   Updated: 2023/12/07 19:16:28 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int	get_height(char *file_name)
{
	int	height;
	int	fd;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	if (height == 0)
		exit(0);
	return (height);
}

int	get_width(char *file_name)
{
	int	width;
	int	i;
	int	fd;

	fd = open(file_name, O_RDONLY);
	i = 0;
	width = ft_nbr_counter(get_next_line(fd), ' ');
	close(fd);
	return (width);
}

void	matrix_insertion(int *matrix_row, char *line)
{
	char	**nbrs;
	int		i;

	nbrs = ft_split(line, ' ');
	i = 0;
	while (nbrs[i])
	{
		matrix_row[i] = ft_atoi(nbrs[i]);
		free(nbrs[i]);
		i++;
	}
}

void	file_reader(char *file_name, t_win *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = get_height(file_name);
	data->matrix = (int **)malloc((data->height + 1) * sizeof(int *));
	data->width = get_width(file_name);
	i = 0;
	while (i <= data->height)
		data->matrix[i++] = (int *)malloc((data->width + 1) * sizeof(int));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		matrix_insertion(data->matrix[i], line);
		free(line);
		i++;
	}
	data->matrix[i] = NULL;
}
