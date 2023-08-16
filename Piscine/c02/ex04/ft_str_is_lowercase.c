/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:21:17 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/23 13:26:51 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	char	c;
	int		i;
	int		is_lowercase;

	i = 0;
	is_lowercase = 1;
	while (str[i])
	{
		c = str[i];
		if (c < 'a' || c > 'z')
			is_lowercase = 0;
		i++;
	}
	return (is_lowercase);
}
