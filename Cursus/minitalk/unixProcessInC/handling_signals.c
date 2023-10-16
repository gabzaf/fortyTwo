/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:59:11 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/16 11:37:32 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void	signal_handler_sigstop(int sig)
{
	printf("\nStop not allowed.\n");
}

void	signal_handler_sigcont(int sig)
{
	printf("Input number: ");
	fflush(stdout);
}

int	main(void)
{
	struct	sigaction sact;
	int	x;
	
	//sact.sa_handler = &signal_handler_sigstop;
	sact.sa_handler = &signal_handler_sigcont;
	sact.sa_flags = SA_RESTART;
	//sigaction(SIGTSTP, &sact, NULL);
	sigaction(SIGCONT, &sact, NULL);
	//signal(SIGTSTP, &signal_handler_sigstop);	
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}
