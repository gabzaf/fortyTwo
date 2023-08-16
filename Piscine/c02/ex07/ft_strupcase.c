/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:54:00 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/27 12:21:55 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[4];
	int		i;

	i = 0;
	str[0] = 'a';
	str[1] = 'e';
	str[2] = 'h';
	str[3] = 'o';
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
	printf("%s", ft_strupcase(str));
	return (0);
}*/
