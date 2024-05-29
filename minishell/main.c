/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:14:21 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/29 17:22:07 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_terminal(t_terminal *terminal, char **env)
{
	terminal->env = env;
	terminal->input = NULL;
	terminal->env_path = getenv("PATH");
	terminal->split_input = NULL;
	terminal->inputs = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_terminal	terminal;

	ft_init_terminal(&terminal, env);
	while (1)
	{
		ft_get_inputs(&terminal);
	}
	return (0);	
}
