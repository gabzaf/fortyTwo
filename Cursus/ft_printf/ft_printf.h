/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:02:51 by gamado-x          #+#    #+#             */
/*   Updated: 2023/09/17 12:34:46 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_verify_format(va_list args, char *str, int i, int *count);
int		ft_strlen(const char *s);
void	ft_putchar_ft_printf(char c, int *count);
void	ft_putstr_ft_printf(char *s, int *count);
void	ft_putnbr_ft_printf(int nbr, int *count);
void	ft_baseputnbr_ft_printf(unsigned int nbr, char *base, int *count);
void	ft_pointer_printer(unsigned long ptr, char *base, int *count);
void	ft_pointer_putnbr(unsigned long ptr, char *base, int *count);

#endif
