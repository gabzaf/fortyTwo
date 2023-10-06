/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:55:00 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/03 19:49:09 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

//gotcha handles the SIGINT signal. signum is the signal number
void	gotcha(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

//handle signal handles how a signal will be processed
int	handle_signal(void)
{
	if (signal(SIGINT, gotcha) == SIG_ERR)
		return (-1);
	if (signal(SIGQUIT, gotcha) == SIG_ERR)
		return (-1);
	//signum does not support SIGSTOP, if I use it, It gets me the failure msg
	/*if (signal(SIGSTOP, gotcha) == SIG_ERR)
		return (-1);*/
	return (0);
}

int	main(void)
{
	int	i;

	if (handle_signal() == -1)
	{
		printf("Failure\n");
		return (EXIT_FAILURE);
	}
	for(i = 0; ; i++)
	{
		printf("[%d] Wait for it ...\n", i);
		sleep(1);
	}
	return (EXIT_SUCCESS);
}

