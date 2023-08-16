/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marloaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:59:52 by marloaur          #+#    #+#             */
/*   Updated: 2023/03/19 11:34:14 by marloaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_args(char **argv)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (argv[1][++i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (-1);
		n++;
		if (argv[1][i + 1] == '\0')
			return (n);
		else if (argv[1][i + 1] != ' ')
			return (-1);
		i++;
	}
	return (n);
}

int	**get_args(char **argv, int size)
{
	int	i;
	int	j;
	int	**tab;

	tab = malloc(sizeof(int*) * (size / 4));
	i = -1;
	j = 0;
	while (argv[1][++i])
	{
		if (j % (size / 4) == 0)
			tab[j / (size / 4)] = malloc(sizeof(int) * (size / 4));
		tab[j / (size / 4)][j % (size / 4)] = argv[1][i] - '0';
		if (argv[1][i + 1] != '\0')
			i++;
		j++;
	}
	return (tab);
}

int	**args(int argc, char **argv, int *size)
{
	int	nargs;
	int	**args;

	if (argc == 2)
	{
		nargs = count_args(argv);
		if (nargs == -1 || nargs % 4 != 0 || nargs < 12)
		{
			return (NULL);
		}
		else
		{
			*size = nargs / 4;
			args = get_args(argv, nargs);
			return (args);
		}
	}
	return (NULL);
}
