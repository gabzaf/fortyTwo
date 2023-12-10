/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:53:23 by gamado-x          #+#    #+#             */
/*   Updated: 2023/12/09 16:26:01 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int	get_height(char *file_name)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
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
	free(nbrs);
}

void	row_allocation(t_win *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		data->matrix[i] = (int *)malloc((data->width + 1) * sizeof(int));
		if (!data->matrix[i])
			exit(0);
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
	if (!data->matrix)
		exit(0);
	data->width = get_width(file_name);
	row_allocation(data);
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
	close(fd);
}
