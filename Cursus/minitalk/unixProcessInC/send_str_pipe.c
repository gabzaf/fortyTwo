/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_str_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:42:10 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/16 17:19:06 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

int	main(void)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		close(fd[0]);
		char	str[200];
		int	n;

		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';
		n = strlen(str) + 1;
		if (write(fd[1], &n, sizeof(int)) < 0)
			return (3);
		if (write(fd[1], str, sizeof(char) * n) < 0)
			return (4);
		close (fd[1]);
	}
	else
	{
		close(fd[1]);
		char	str[200];
		int	n;

		if (read(fd[0], &n, sizeof(int)) < 0)
			return (5);
		if (read(fd[0], str, sizeof(char) * n) < 0)
			return (6);
		printf("Received: %s\n", str);
		close(fd[0]);
		wait(NULL);
	}
	return(0);
}
