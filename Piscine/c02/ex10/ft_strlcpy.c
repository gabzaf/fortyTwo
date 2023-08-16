/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:44:58 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/23 18:50:28 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (src[length])
		length++;
	if (size < 1)
		return (length);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

/*int	main(void)
{
	char	src[5];
	char	dest[5];

	src[0] = 'a';
	src[1] = '1';
	src[2] = 'e';
	src[3] = '7';
	src[4] = '\0';
	printf("%d", ft_strlcpy(dest, src, 5));
	return (0);
}*/
