/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:06:13 by gamado-x          #+#    #+#             */
/*   Updated: 2023/12/09 17:50:58 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_color(int z, int z1)
{
	if (z || z1)
	{
		if (z1 > 11 && z1 <= 30)
			return (0x830707);
		if (z1 > 30 && z1 < 50) 
			return (0x983030);
		if (z > 10)
			return (0x008000);
		return (0xeB0c0c);
	}
	else
		return (0xffffff);
}

void	screen_fit(float *x, float *x1, float *y, float *y1)
{
	*x += 950;
	*y += 30;
	*x1 += 950;
	*y1 += 30;
}
