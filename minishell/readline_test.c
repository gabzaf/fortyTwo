/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:37:39 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/27 19:11:27 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "readline/readline.h"

int	main(int argc, char **argv)
{
	char	*current_line = readline("minishell> ");
	printf("You entered: \"%s\"\n", current_line);

	free(current_line);

	return(0);
}
