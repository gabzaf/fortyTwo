/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:04:20 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/18 11:28:31 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	signal_handler_sigusr(int sig)
{
	if (sig == SIGUSR1)
		//write(1, "1", 1);

	if (sig == SIGUSR2)
		//write(1, "0", 1);

}

int	main(void)
{
	struct	sigaction sact;

	printf("%d\n", getpid());
	sact.sa_flags = 0;
	sact.sa_handler = &signal_handler_sigusr;
	while (1)
	{
		sigaction(SIGUSR1, &sact, NULL);
		sigaction(SIGUSR2, &sact, NULL);
		sleep(1);
	}
	return (0);
}
