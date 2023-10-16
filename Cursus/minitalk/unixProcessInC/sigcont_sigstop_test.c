/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigcont_sigstop_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:59:17 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/15 17:33:46 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int	main(void)
{
	int	pid;
	int	t;

	pid = fork();
	if (pid == -1)
	{
		return (1);
	}
	if (pid == 0)
	{
		while (1)
		{
			printf("Some output\n");
			usleep(50000);
		}
	}
	else
	{
		kill(pid, SIGSTOP);
		do
		{
			printf("Time in seconds for execution: ");
			scanf("%d", &t);
			if (t > 0)
			{
				kill(pid, SIGCONT);
				sleep(t);
				kill(pid, SIGSTOP);
			} 
		}
		while (t > 0);	
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
