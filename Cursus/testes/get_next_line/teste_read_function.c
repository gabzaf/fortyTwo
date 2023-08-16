/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_read_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:15:43 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/24 09:44:43 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	int	bytes;
	char	buff[1024];
	char	path[] = "/nfs/homes/gamado-x/Documents/Cursus/testes/get_next_line/example.txt";

	fd = open(path, O_RDONLY);
	bytes = read(fd, buff, 10);
	printf("%d\n\n", bytes);
	printf("%s\n\n", buff);
	return (0);
}
