/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:05:07 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/16 10:16:42 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	char	i;

	i = '5';
	write(1, &i, 1);
	write(1, "\n", 1);
	while (i >= '0')
	{
		write(1, &i, 1);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}

	