/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:01:23 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/12 19:30:25 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int	main(void)
{
	int	arr[5];
	int	fd;
	int	i;
	int	sum;

	fd = open("/nfs/homes/gamado-x/sum", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (i < 5)
	{
		if (read(fd, &arr[i], sizeof(int)) == -1)
			return (0);
		printf("Received %d\n", arr[i]);
		i++;
	}
	close(fd);
	sum = 0;
	i = 0;
	while (i < 5)
	{
		sum += arr[i];
		i++;
	}
	printf("Result is %d\n", sum);
	return (0);
}
