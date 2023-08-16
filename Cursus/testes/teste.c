/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:01:27 by gamado-x          #+#    #+#             */
/*   Updated: 2023/08/08 11:16:05 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	function (char **str)
{
	*str = "Hello, World!";
}

int	main()
{
	static char	*str;

	str = "Ola, Mundo!";
	printf("%s", str);
	function(&str);
	printf("%s", str);
	return (0);
}
