/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:04:09 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/06 14:09:10 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);

int	main (int argc, char **argv)
{
	if (argc < 1)
		return (0);
	kill(argv[1], 	);
	printf("%zu", ft_strlen(argv[2]));
	return (0);
}
