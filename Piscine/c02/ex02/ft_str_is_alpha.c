/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:56:43 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/23 13:00:52 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	char	c;
	int		i;
	int		is_alpha;

	i = 0;
	is_alpha = 1;
	while (str[i])
	{
		c = str[i];
		if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
			is_alpha = 0;
		i++;
	}
	return (is_alpha);
}

/*int	main(void)
{
	char	str[4];
	int		alpha;
	int		i;

	i = 0;
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	alpha = ft_str_is_alpha(str);
	printf("%d\n", alpha);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
}*/
