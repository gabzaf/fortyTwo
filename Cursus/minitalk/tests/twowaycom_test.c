/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twowaycom_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:30:01 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/13 08:34:03 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int	main(void)
{
	int	fd1[2]; //c => p
	int	fd2[2]; //p => c 
	int	pid;
	int	x;
//To set it up right, I first have to close some of the FDs 'cause I have too many.
//The 1st fd, the child, only writes.
	if (pipe(fd1) == -1 || pipe(fd2) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		close(fd1[0]);
		close(fd2[1]);
		if (read(fd2[0], &x, sizeof(x)) == -1)
			return (0);
		printf("Received %d\n", x);
		x *= 4;
		if (write(fd1[1], &x, sizeof(x)) == -1)
			return (0);
		printf("Wrote %d\n", x);
		close(fd1[1]);
		close(fd2[0]);
	}
	else
	{
		close(fd1[1]);
		close(fd2[0]);
		srand(time(NULL));
		int y = rand() % 10;
		if (write(fd2[1], &y, sizeof(y)) == -1)
			return (0);
		//printf("Wrote %d\n", y);
		if (read(fd1[0], &y, sizeof(y)) == -1)
			return (0);
		printf("Result is %d\n", y);
		close(fd1[0]);
		close(fd2[1]);
		wait(NULL);
	}
	return(0);
}
