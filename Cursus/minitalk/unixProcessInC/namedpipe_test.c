/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namedpipe_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:07:52 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/12 17:52:25 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	x;

	if (mkfifo("/nfs/homes/gamado-x/myfifo", 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("FIFO file could not be created\n");
			return (0);
		}
	}
	fd = open("/nfs/homes/gamado-x/myfifo", O_WRONLY);
	if (fd == -1)
		return (0);
	x = 97;
	if (write(fd, &x, sizeof(x)) == -1)
		return (2);
	close(fd);
	return (0);
}
