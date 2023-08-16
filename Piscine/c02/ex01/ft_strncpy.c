/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:31:07 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/27 12:12:44 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	src[10] = "0 1 2 3 4";
	char	dest[10];
	char	*result;
	int		size;
	int		i;

	i = 0;
	size = 10;
	result = ft_strncpy(dest, src, size);
	while (i <= 8)
	{
		printf("%c", result[i]);
		i++;
	}
	return (0);
}*/
