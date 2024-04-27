/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:16:09 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/25 20:08:10 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	check_input(int argc, char **argv)
{
	int	i;
	int	input;
	int	d;

	i = 1;
	while (i < argc)
	{
		NO ARGV TEM OS ESPACOS?
		ft_printf("%d\n", i);
		input = ft_atoi(argv[i]);
		ft_printf("%d\n", input);
		d = ft_isdigit(input);
		ft_printf("%d\n", d);
		i++;
	}
}
