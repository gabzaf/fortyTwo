/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:16:09 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/23 21:02:13 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

int	check_long(char *str)
{
	if (INT_MIN <= ft_atol(str) && ft_atol(str) <= INT_MAX)
		return (1);
	else
		return (0);
}

int	check_int(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
		i++;
	if (argv[i] == '\0')
		return (1);
	return (0);
}

int	check_dplctd_nbr(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_int(argv[i]) || !check_long(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
