/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_exclamacao.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:42:18 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/03 17:21:21 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_verify_exclamation(int positive)
{
	if (positive > 0)
		return (1);
	else
		return (0);
}

int	main()
{
	int	n = 2;
	//linha abaixo verifica se retorno da funcao chamada eh igual zero
	if (!ft_verify_exclamation(n))
		printf("Negativo");
	else
		printf("Positivo");
	return (0);
}
