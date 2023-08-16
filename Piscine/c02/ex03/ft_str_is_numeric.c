/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:01:49 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/23 13:20:22 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	char	c;
	int		i;
	int		is_digit;

	i = 0;
	is_digit = 1;
	while (str[i])
	{
		c = str[i];
		if (c < '0' || c > '9')
			is_digit = 0;
		i++;
	}
	return (is_digit);
}

/*int	main(void)
{
	char	str[4];

	str[0] = '0';
	str[1] = '1';
	str[2] = '2';
	str[3] = 'a';
	printf("%d", ft_str_is_numeric(str));
	return (0);
}*/
