/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:32:58 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/19 14:08:30 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/

void	ft_putchar(char output)
{
	write(1, &output, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

/*int	main(void)
{
	char	*str;

	str = (char *) calloc(15, sizeof(char));
	if (str == NULL)
	{
		printf("ERRO");
	}
	strcpy(str, "Ola, mundo!!!!");
	ft_putstr(str);
	free(str);
	return (0);
}*/
