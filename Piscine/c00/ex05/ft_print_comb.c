/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:48:54 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/19 11:22:40 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char output)
{
	write(1, &output, 1);
}

void	ft_putchar_inputs(char dl, char dm, char dr)
{
	ft_putchar(dl + '0');
	ft_putchar(dm + '0');
	ft_putchar(dr + '0');
	if (dl != 7 || dm != 8 || dr != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	digit_left;
	int	digit_mid;
	int	digit_right;

	digit_left = 0;
	while (digit_left <= 7)
	{
		digit_mid = digit_left + 1;
		while (digit_mid <= 8)
		{
			digit_right = digit_mid + 1;
			while (digit_right <= 9)
			{
				ft_putchar_inputs(digit_left, digit_mid, digit_right);
				digit_right++;
			}
			digit_mid++;
		}
		digit_left++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
