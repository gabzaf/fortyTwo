/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:23:26 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/29 17:48:13 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

char	*ft_strdup(char *src)
{
	char	*new_array;
	int		length;
	int		k;

	length = 0;
	k = 0;
	while (src[length])
		length++;
	new_array = malloc((length + 1) * sizeof(char));
	length = 0;
	while (src[length])
	{
		new_array[k] = src[length];
		length++;
		k++;
	}
	new_array[k] = '\0';
	return (new_array);
}

/*int	main(void)
{
	char	src[] = "Ola,mundo!";
	printf("Minha funcao: %s\n", ft_strdup(src));
	printf("Strdup: %s", strdup(src));
	return (0);
}*/
