/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2nd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:00:11 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/12 13:30:22 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int	array[] = { 1, 2, 3, 4, 5, 6 };
	int	arrayLen;
	int	fd[2];
	int	id;
	int	start;
	int	end;
	int	sum;
	int	i;
	int	sumFromChild;
	int	ttSum;

	arrayLen = sizeof(array) / sizeof(int);
	if (pipe(fd) == -1)
		return (0);
	id = fork();
	if (id == -1)
		return (0);
	if (id == 0)
	{
		start = 0;
		end = arrayLen / 2;
	}
	else
	{
		start = arrayLen / 2;
		end = arrayLen;
	}
	sum = 0;
	i = start;
	while (i < end)
	{
		sum += array[i];
		i++;
	}
	printf("Calculated partial sum: %d\n", sum);
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);
		ttSum = sum + sumFromChild;
		printf("Total sum is %d\n", ttSum);
		wait(NULL);
	}
	return (0);
}
