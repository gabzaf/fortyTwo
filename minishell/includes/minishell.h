/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:17:01 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/29 17:21:32 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>

typedef struct	t_input
{
	char	*value;
	t_token	token;
	int	s_quoted;
	int	d_quoted;
	struct	t_input *next;
	struct	t_input	*prev;
}	t_input;

typedef struct	t_terminal
{
	char	*input;
	char	**split_input;
	char	*env_path;
	char	**env;
	t_input	**inputs;
}	t_terminal;

#endif
