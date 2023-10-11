/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_2nd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:20:24 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/11 16:47:18 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int	main(int argc, char **argv)
{
	int	id;
	int	n;
	int	i;

	id = fork();
	if (id == 0)
		n = 0;
	else
		n = 5;
	if (id !=0)
	{
		wait(0);
	}
	i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		//fflush(stdout);
		i++;
	}
	if (id != 0)
		printf("\n");
	return (0);
}
