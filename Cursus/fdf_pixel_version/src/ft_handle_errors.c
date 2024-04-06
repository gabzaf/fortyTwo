/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:29:32 by gamado-x          #+#    #+#             */
/*   Updated: 2023/12/09 14:46:05 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	input_error(int argc, char *argv)
{
	int	fd;

	if (argc != 2)
		exit(0);
	fd = open(argv, O_RDONLY, 0);
	if (fd == -1)
		exit(0);
	else
		close(fd);
}
