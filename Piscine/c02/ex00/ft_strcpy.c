/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:37 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/27 12:07:24 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	src[6] = "0 1 2";
	char	dest[6];
	char	*result;
	int		i;

	i = 0;
	result = ft_strcpy(dest, src);
	while (i < 6)
	{
		printf("array_var_value: %c array_var_address: %p", result[i], &result[i]);
		printf("\n");
		i++;
	}
	return (0);
}*/
