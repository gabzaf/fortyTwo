/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:33:46 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/23 17:44:17 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	char	c;
	int		i;
	int		next;

	i = 0;
	next = 1;
	while (str[i])
	{
		c = str[i];
		if ((next == 1) && (c >= 'a') && (c <= 'z'))
			str[i] -= 32;
		else if ((next == 0) && (c >= 'A') && (c <= 'Z'))
			str[i] += 32;
		if ((c < '0') || (c > '9' && c < 'A'))
			next = 1;
		else if ((c > 'Z' && c < 'a') || (c > 'z'))
			next = 1;
		else
			next = 0;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[65] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et_un";

	printf("%s", ft_strcapitalize(str));
	return (0);
}*/
