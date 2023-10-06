/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigemptyset_2nd_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:14:32 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/05 13:21:37 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void 	sigusr2_handler(int signum)
{
    printf("Received SIGUSR2 signal (%d)\n", signum);
}

int 	main(void)
{
    struct 	sigaction sact;

    sigemptyset(&sact.sa_mask);
    sact.sa_flags = 0;
    sact.sa_handler = sigusr2_handler;
    sigaction(SIGUSR2, &sact, NULL);
    printf("Before kill()\n");
    kill(getpid(), SIGUSR2);
    // Sleep to allow time for the signal handler to execute
    sleep(1);
    printf("After kill()\n");
    return (0);
}
