/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:15 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/23 16:33:12 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[4];

	str[0] = 'A';
	str[1] = 'F';
	str[2] = 'J';
	str[3] = 'O';
	printf("%s", ft_strlowcase(str));
	return (0);
}*/
