/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:06:13 by gamado-x          #+#    #+#             */
/*   Updated: 2023/12/07 19:11:08 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_color(int z, int z1)
{
	if (z || z1)
		return (0xeB0c0c);
	else
		return (0xffffff);
}

void	point_factor(float *x, float *x1, float *y, float *y1)
{
	*x += 150;
	*y += 150;
	*x1 += 150;
	*y1 += 150;
}
