/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:04:09 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/18 11:17:35 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
int	ft_atoi(const char *nptr);

void	ascii_sender(int pid, int c)
{
	int	bit;
	int	digit;

	bit = 0;
	digit = 1;
	while (bit < 8)
	{
		if ((c & digit << bit) != 0)
				kill(pid, SIGUSR1);
				
		else
				kill(pid, SIGUSR2);
		usleep(5000);
		bit++;
	}
}

void	text_sender(int pid, char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		ascii_sender(pid, str[i]);		
		i++;
	}
}

int	main (int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	text_sender(pid, argv[2]);
	return (0);
}
