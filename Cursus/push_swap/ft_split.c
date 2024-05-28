/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:17:37 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/28 13:16:15 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
		i++;
	return (i);
}

static char	*ft_alloc_and_insert(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**split_util(char **tab, char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str)) && index >= 0)
		{
			tab[j++] = ft_alloc_and_insert(str, index, i);
			index = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

static int	count_words(char const *str, char c)
{
	int	counted_words;
	int	flag;

	counted_words = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			counted_words++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (counted_words);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	if (!str)
		return (0);
	tab = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	return (split_util(tab, str, c));
}
