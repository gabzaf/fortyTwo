/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:04:20 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/06 13:43:39 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	sigusr1_handler(int signum)
{
	printf("Recebi o sinal do client!!");
}

int	main(void)
{
	struct	sigaction sact;

	printf("%d\n", getpid());
	pause();
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = 0;
	sact.sa_handler = sigusr1_handler;




	return (0);
}
