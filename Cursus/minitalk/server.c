/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:04:20 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/30 13:38:52 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_received_str;

void	signal_handler_sigusr(int sig)
{
	static int	received_byte;
	static int	bit_count;
	char		*ascii_c;

	if (sig == SIGUSR1)
		received_byte |= (0x01 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		ascii_c = (char *)malloc(sizeof(char) * 2);
		if (!ascii_c)
			return ;
		ascii_c[0] = (char)received_byte;
		ascii_c[1] = '\0';
		g_received_str = ft_strjoin(g_received_str, ascii_c);
		if (ascii_c[0] == '\n')
		{
			ft_putstr_fd(g_received_str, 1);
			free(g_received_str);
			g_received_str = NULL;
		}
		received_byte = 0;
		bit_count = 0;
		free(ascii_c);
	}
}

int	main(void)
{
	struct sigaction	sact;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sact.sa_flags = 0;
	sact.sa_handler = &signal_handler_sigusr;
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
		pause();
	return (0);
}
