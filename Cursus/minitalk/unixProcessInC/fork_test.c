/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:11:28 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/11 13:53:21 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	id;
	       
	id = fork();
	if (id != 0)
		fork();
	//fork();
	printf("Hello, world from id: %d\n", id);
	/*if (id == 0)
		printf("Hello from the child process.\n");
	else
		printf("Hello from the parent process.\n");*/	
	return (0);
}
