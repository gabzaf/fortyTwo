/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:02:44 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/12 12:25:24 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	//fd[0] - read
	//fd[1] - write
	int	fd[2];
	int	id;
	int	x;
	int	y;

	if (pipe(fd) == -1)
	{
		printf("An error appeared when opening the file.\n");
		return (1);
	}

	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
			return (2);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &y, sizeof(int)) == -1)
			return (3);
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}
