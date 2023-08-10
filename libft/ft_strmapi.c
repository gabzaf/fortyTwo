/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:10:48 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/21 12:46:10 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstring;

	i = 0;
	newstring = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!newstring)
		return (NULL);
	while (s[i])
	{
		newstring[i] = (*f)(i, s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
