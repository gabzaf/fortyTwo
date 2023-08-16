/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exygor_teste.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:15:12 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/30 13:23:09 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	occ_a(char *str)
{
	int	letter;
	int	i;

	i = 0;
	letter = 0;
	while (str[i])
	{
		if (str[i] == 'A')
			letter++;
		i++;
	}
	return (letter);
}

int	main(void)
{
	char	str[] = "OlA, Ygor. Tudo bem? OlA";
	printf("%d", occ_a(str));
	return (0);
}
