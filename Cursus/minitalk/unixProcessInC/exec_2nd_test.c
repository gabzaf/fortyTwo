/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2nd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:11:25 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/14 11:54:11 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int	pid;
	int	err;
	int	wstatus;
	int	statusCode;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find the program to execute\n");
			return (2);
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
