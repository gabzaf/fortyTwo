/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:37:43 by gamado-x          #+#    #+#             */
/*   Updated: 2023/08/07 10:20:06 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		v;
	char	*strToReturn;

	i = 0;
	v = 0;
	//memalloc from line and bfline
	strToReturn = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strToReturn)
		return (NULL);
	//1st checks if the ptr isnt NULL
	//2nd checks if the index isnt null char
	while (s1 && s1[v])
		strToReturn[i++] = s1[v++];
	v = 0;
	while (s2 && s2[v])
	{
		strToReturn[i] = s2[v++];
		if (strToReturn[i++] == '\n')
			break ;
	}
	strToReturn[i] = '\0';
	free (s1);
	return (strToReturn);
}
//removes all chars after the 1st nwl char
int	ft_clean(char *str)
{
	int	i;
	int	j;
	int	is_nwl;

	i = 0;
	j = 0;
	is_nwl = 0;
	while (str[i])
	{
		if (is_nwl)
			str[j++] = str[i];
		if (str[i] == '\n')
			is_nwl = 1;
		str[i] = '\0';
		i++;
	}
	return (is_nwl);
}
