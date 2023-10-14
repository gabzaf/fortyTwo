/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_intro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:50:10 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/14 13:00:32 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int	main(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while(1)
		{
			printf("Some text goes here\n");
			usleep(50000);
		}
	}
	else
	{
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
