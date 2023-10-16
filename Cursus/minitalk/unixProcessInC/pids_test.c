/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:08:56 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/11 18:01:42 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int	id;

	id = fork();
	if (id == 0)
		sleep(1);
	printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
	wait(NULL);
	return (0);
}
