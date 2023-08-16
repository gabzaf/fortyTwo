/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marloaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:04:14 by marloaur          #+#    #+#             */
/*   Updated: 2023/03/19 11:04:50 by marloaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	lock_hori(int ***table, int **bord, int size, int i)
{
	int	j;

	if (bord[0][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][j][i] = j + 1;
	}
	else if (bord[0][i] == 1)
		table[1][0][i] = size;
	if (bord[1][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][size - j - 1][i] = j + 1;
	}
	else if (bord[1][i] == 1)
		table[1][size - 1][i] = size;
}

void	lock_vert(int ***table, int **bord, int size, int i)
{
	int	j;

	if (bord[2][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][i][j] = j + 1;
	}
	else if (bord[2][i] == 1)
		table[1][i][0] = size;
	if (bord[3][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][i][size - j - 1] = j + 1;
	}
	else if (bord[3][i] == 1)
		table[1][i][size - 1] = size;
}

void	assemble(int ***table, int **bord, int size, int i)
{
	int	j;

	j = -1;
	table[2][i] = malloc(sizeof(int) * size);
	while (++j < size)
	{
		table[2][i][j] = bord[i][j];
	}
}

void	lock(int ***table, int **bord, int size)
{
	int	i;

	table[2] = malloc(sizeof(int*) * 4);
	i = -1;
	while (++i < 4)
	{
		lock_hori(table, bord, size, i);
		lock_vert(table, bord, size, i);
		assemble(table, bord, size, i);
	}
}

