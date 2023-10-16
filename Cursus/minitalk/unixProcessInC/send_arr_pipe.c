/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_arr_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:51:16 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/16 15:34:51 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

//2 processes
//Child process should generate random numbers and send them to the parent
//Parent is going to sum all the numbers and print the result


int	main(void)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		close(fd[0]);
		int	arr[10];
		int	n, i;

		srand(time(NULL));
		n = rand() % 10 + 1;
		printf("Generated: ");
		i = 0;
		while(i < n)
		{
			arr[i] = rand() % 11;
			printf("%d ", arr[i]);
			i++;
		}
		printf("\n");
		if (write(fd[1], &n, sizeof(int)) < 0)
			return(3);
		printf("Sent n = %d\n", n);
		if (write(fd[1], arr, sizeof(int) * n) < 0)
			return (4);
		printf("Sent array\n");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int	arr[10];
		int	n, i, sum = 0;

		if (read(fd[0], &n, sizeof(int)) < 0)
			return (5);
		printf("Received n = %d\n", n);
		if (read(fd[0], arr, sizeof(int) * n) < 0)
			return (6);
		printf("Received array\n");
		i = 0;
		close(fd[0]);
		while (i < n)
		{
			sum += arr[i];
			i++;
		}
		printf("Result is: %d\n", sum);
		wait(NULL);
	}
	return (0);
}
