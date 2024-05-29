/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:37:39 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/29 17:17:39 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "readline/readline.h"

void	parsing(char	*line)
{
	while (line)
	{

	}
}

int	main(int argc, char **argv)
{
	while (1)
	{
		char	*current_line = readline("minishell> ");
		if (!current_line)
		{
			printf("Exiting shell\n");
			return (-1);
		}
		parsing(current_line);
		printf("You entered: \"%s\"\n", current_line);
		
		free(current_line);
	}	
	return(0);
}
