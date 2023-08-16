/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:38:31 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/28 11:43:01 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_counter;
	unsigned int	src_counter;

	dest_counter = 0;
	src_counter = 0;
	while (dest[dest_counter])
		dest_counter++;
	while (src[src_counter] && src_counter < nb)
	{
		dest[dest_counter] = src[src_counter];
		dest_counter++;
		src_counter++;
	}
	dest[dest_counter] = '\0';
	return (dest);
}
