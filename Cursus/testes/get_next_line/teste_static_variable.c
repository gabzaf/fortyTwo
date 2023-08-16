/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_static_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:05:07 by gamado-x          #+#    #+#             */
/*   Updated: 2023/06/26 17:16:40 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	fun()
{
	static int	count = 0;
	count++;
	return (count);
}

int	main ()
{
	printf("%d\n", fun());
	printf("%d", fun());
	return (0);
}
