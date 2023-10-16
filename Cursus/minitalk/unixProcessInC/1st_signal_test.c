/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_signal_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:49:26 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/04 13:57:50 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//pq nao funciona??

void	signal_handler(void);

int	register_handler_signal(void)
{
	//sighandler_t signal (int signum, sighandler_t handler);
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (-1);
	return (0);
}

int	register_handler_sigaction(void)
{
	struct	sigaction sa;

	sa.sa_handler = &signal_handler;
	return (sigaction(SIGINT, &sa, NULL));
}

void signal_handler(int signum)
{
	printf("Signal caught!\n");
}

int	main(void)
{
	int	i;

	i = 0;
	if (register_handler_sigaction() == -1)
	{
		printf("Failure\n");
		return (EXIT_FAILURE);
	}
	while (i)
	{
		printf("[%d] Wait for it ...\n", i);
		sleep(1);
		i++;
	}
	return (EXIT_SUCESS);
}
