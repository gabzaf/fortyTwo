/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigemptyset_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:58:48 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/04 15:51:36 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	main(void)
{
	//sact to specify how to handle signals.
	struct	sigaction sact;
	//func below to clear the signal mask for sact, this means that while handling SIGUSR2, no other signals will be blocked.
	sigemptyset(&sact.sa_mask);
	//below indicates no special flags are set for the signal handler.
	sact.sa_flags = 0;
	//SIG_IGN-Request that signal be ignored. Below sets the signal handler for SIGUSR2 to SIG_IGN which means that when the process receives a SIGUSR2 signal, it will ignore it. 
	sact.sa_handler = SIG_IGN;
	//func below installs the sact signal handler for SIGUSR2, so when the process receives SIGUSR2, it will be ignored.
	sigaction(SIGUSR2, &sact, NULL);
	//prints the message "before kill()" to the console.
	printf("before kill()");
	//func below sends a SIGUSR2 signal to the current process using the 'kill' function. However, since I have installed a signal handler that ignores SIGUSR2, the process will not take any action in response to this signal.
	kill(getpid(), SIGUSR2);
	printf("after kill()");
}
