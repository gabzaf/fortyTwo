/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:27:38 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/23 13:31:02 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	char	c;
	int		i;
	int		is_uppercase;

	i = 0;
	is_uppercase = 1;
	while (str[i])
	{
		c = str[i];
		if (c < 'A' || c > 'Z')
			is_uppercase = 0;
		i++;
	}
	return (is_uppercase);
}
