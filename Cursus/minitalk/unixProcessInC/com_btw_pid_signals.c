/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_btw_pid_signals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:46 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/16 12:34:16 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>


int	x = 0;
void	signal_handler_sigusr1(int sig)
{
	if (x == 0)
		printf("HINT -> Remember that multiplication is repetitive addition!\n");
}

int	main(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		struct	sigaction sact = { 0 };
		sact.sa_flags = SA_RESTART;
		sact.sa_handler = &signal_handler_sigusr1;
		sigaction(SIGUSR1, &sact, NULL);
		printf("Whats the result of 3 x 5? ");
		scanf("%d", &x);
		if (x == 15)
			printf("Right!");
		else
			printf("Wrong.");
		wait(NULL);
	}
	return (0);
}
