/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:06:13 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/21 12:19:48 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sr;
	size_t			i;

	sr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sr[i] == (unsigned char)c)
			return ((sr + i));
		i++;
	}
	return (NULL);
}
