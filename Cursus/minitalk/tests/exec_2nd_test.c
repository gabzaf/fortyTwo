/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2nd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:11:25 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/13 11:25:18 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	
	}
	else
	{
		wait(NULL);
		printf("Some post processing goes here!\n");
	}
	printf("Success!");
	return (0);
}
