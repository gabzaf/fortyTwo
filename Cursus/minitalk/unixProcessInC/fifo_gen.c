/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:00:45 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/12 19:19:00 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

int	main(void)
{
	int	arr[5];
	int	i;
	int	fd;

	if ((mkfifo("/nfs/homes/gamado-x/sum", 0777)) == -1)
	{
		if (errno != EEXIST)
		{
			printf("FIFO file could not be created.\n");
			return (0);
		}
	}
	srand(time(NULL));
	i = 0;
	while(i < 5)
	{
		arr[i] = rand() % 100;
		i++;
	}
	fd = open("/nfs/homes/gamado-x/sum", O_WRONLY);
	if (fd == -1)
		return (0);

	i = 0;
	while (i < 5)
	{
		if (write(fd, &arr[i], sizeof(int)) == -1)
			return (0);
		printf("Wrote %d\n", arr[i]);
		i++;
	}
	close (fd);
	return (0);
}
