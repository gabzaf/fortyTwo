/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:22:26 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/29 18:01:23 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_get_inputs(t_terminal *terminal)
{
	terminal->input = readline("\033[33mMinishell$\033[0m");
	if (!terminal->input)
		return ;
	terminal->split_input = ft_split_input(terminal->input);
	terminal->inputs = ft_construct_inputs((const char **)
			terminal->split_input);
}
