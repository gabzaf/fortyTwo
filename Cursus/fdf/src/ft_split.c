/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:47:06 by gamado-x          #+#    #+#             */
/*   Updated: 2023/11/10 08:37:02 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
//na funcao abaixo testar passar a tab como parametro e fazer free da word
static char	*ft_allocate_insert(const char *string, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		word[i] = string[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_all_ins_helper(const char *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			tab[j] = ft_allocate_insert(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	tab[j] = 0;
}

static int	ft_countwords(char const *string, char c)
{
	int	i;
	int	countedwords;
	int	flag;

	i = 0;
	countedwords = 0;
	flag = 0;
	while (string[i])
	{
		if (string[i] != c && flag == 0)
		{
			flag = 1;
			countedwords++;
		}
		else if (string[i] == c)
			flag = 0;
		i++;
	}
	return (countedwords);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	ft_all_ins_helper(s, c, tab);
	return (tab);
}
