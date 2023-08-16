/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:58:30 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/18 19:44:49 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//void	ft_view_control(char **argv);

void	ft_putchar(char output)
{
	printf("%c", output);
	printf(" ");
}

int	ft_square_root(int string_qtty)
{
	int	i = 0;
	while (i < string_qtty)
	{
		if (i * i == string_qtty)
			return (i);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		printf("%s\n", "Error");
	int	i;
	int	space_counter;
	char	*array;

	i = 0;
	space_counter = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			space_counter++;
		i++;
	}
	int string_qtty = space_counter + 2;
	array = (char*) malloc((string_qtty + space_counter) * sizeof(char));
	if (array == NULL)
		printf("Erro de alocacao");
	while (i <= string_qtty + space_counter)
	{
		array[i] = argv[1][i];
		printf("%c", array[i]);
		i++;
	}
	int matrix_size = ft_square_root(string_qtty) + 2;
//	ft_view_control(argv);
	free(array);
	return (0);
}
