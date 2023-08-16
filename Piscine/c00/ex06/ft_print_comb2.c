/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:26:10 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/19 11:47:17 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char output)
{
	write(1, &output, 1);
}

void	ft_handle_number(int ln, int rn, int i[])
{
	if (ln >= 10)
	{
		i[0] = ln / 10;
		i[1] = ln - 10 * i[0];
	}
	else
	{
		i[0] = 0;
		i[1] = ln;
	}
	if (rn >= 10)
	{
		i[2] = rn / 10;
		i[3] = rn - 10 * i[2];
	}
	else
	{
		i[2] = 0;
		i[3] = rn;
	}
}

void	ft_putchar_inputs(int ln, int rn)
{
	int	number[4];

	ft_handle_number(ln, rn, number);
	ft_putchar(number[0] + '0');
	ft_putchar(number[1] + '0');
	ft_putchar(' ');
	ft_putchar(number[2] + '0');
	ft_putchar(number[3] + '0');
	if (ln != 98 || rn != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	left_number;
	int	right_number;

	left_number = 0;
	while (left_number <= 98)
	{
		right_number = left_number + 1;
		while (right_number <= 99)
		{
			ft_putchar_inputs(left_number, right_number);
			right_number++;
		}
		left_number++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
