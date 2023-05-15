/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:10:18 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/15 19:11:36 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	ft_allocate(char **tab, char *s, char c)
{
	int	i;

	i = 0;	
	string = malloc((nchar + 1) * sizeof(char));
	if (!string)
		return (NULL);
	return (string);
}

static void	ft_countchars(char **tab, const char *s, char c, int size)
{
	int	i;
	int	countedchars;
	int	n;

	i = 0;
	n = 0
	while (s[i] && n < size)
	{
		countedchars = 0;
		while(s[i] == c)
			i++;
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				countedchars++;
				i++;
			}
			tab[n] = ft_allocate(s[i], countedchars);
			n++;
		}
	}	
}

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	countedwords;

	i = 0;
	countedwords = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			countedwords++;
			while (s[i] != c)
				i++;
		}
	}
	return (countedwords);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		tabsize;

	if (!s)
		return (NULL);
	tabsize = ft_countwords(s, c);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	ft_countchars(tab, s, c, tabsize);
	ft_allocate(tab, s, c);
	return (tab);
}

int	main(void)
{

	return (0);
}
