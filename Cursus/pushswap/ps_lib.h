/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:10 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/25 20:06:27 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <unistd.h>

typedef struct s_list
{
	int	value;
	int	index;
	struct	s_list	*next;
}	t_list;

int		ft_printf(const char *format, ...);
int		check_dplctd_nbr(int argc, char **argv);
void	ft_verify_format(va_list args, const char *str, int i, int *count);
int		ft_strlen(const char *s);
void	ft_putchar_ft_printf(const char c, int *count);
void	ft_putstr_ft_printf(const char *s, int *count);
void	ft_putnbr_ft_printf(int nbr, int *count);
void	ft_baseputnbr_ft_printf(unsigned int nbr, char *base, int *count);
void	ft_pointer_printer(unsigned long ptr, char *base, int *count);
void	ft_pointer_putnbr(unsigned long ptr, char *base, int *count);
int		check_input(int argc, char **argv);
int     ft_atoi(const char *nptr);
int	ft_atol(const char *nptr);
int     ft_isdigit(int c);
void	array_insertion(int argc, char **argv, int *array);
void	list_insertion(int argc, char **argv, t_list **a);
void	push_swap(int *array, t_list *a, t_list *b);
int	sort_check(t_list *stack);
int	stack_len(t_list *stack);

#endif
