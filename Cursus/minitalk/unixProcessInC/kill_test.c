/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:17:47 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/05 15:23:44 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	printf("My PID is %d\n", getpid());
	sleep(5);
	kill(getpid(), SIGSEGV);
	return (0);
}
