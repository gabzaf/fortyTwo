/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_3rd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:11:25 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/14 11:59:42 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

int	main(void)
{
	int	pid;
	int	err;
	int	wstatus;
	int	statusCode;
	int	fd;
	int	fd2;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		fd = open("/nfs/homes/gamado-x/pingresults.txt", O_WRONLY | O_CREAT, 0777);
		if (fd == -1)
			return (2);
		fd2 = dup2(fd, STDOUT_FILENO);
		close(fd);
		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find the program to execute\n");
			return (3);
		}
	}
	else
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Success!\n");
			else
				printf("Failure\n");
		}
		printf("Some post processing goes here!\n");
	}
	return (0);
}
