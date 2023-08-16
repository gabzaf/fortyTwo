/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:08:44 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/08 16:25:01 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	addindex(unsigned int i, char c)
{
	return (c + i);
}

static void	printchar(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	int	i;

	i = 1;
	while (i < 35)
	{
		switch (i)
		{
			case 1:
				printf("FT_ISALPHA checks for an alphabetic character.\n");
				printf("----------------------------------------------\n");
				printf("1st test - Checks for 'q'.\n");
				printf("1st test result: %d\n", ft_isalpha('q'));
				printf("2nd test - Checks for '7'.\n");
				printf("2nd test result: %d\n", ft_isalpha('7'));
				printf("3rd test - Checks for 123.\n");
				printf("3rd test result: %d\n", ft_isalpha(123));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 2:
				printf("FT_ISDIGIT checks for a digit (0 through 9).\n");
				printf("----------------------------------------------\n");
				printf("1st test - Checks for '0'.\n");
				printf("1st test result: %d\n", ft_isdigit('0'));
				printf("2nd test - Checks for 'd'.\n");
				printf("2nd test result: %d\n", ft_isdigit('d'));
				printf("3rd test - Checks for 48.\n");
				printf("3rd test result: %d\n", ft_isdigit(48));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 3:
				printf("FT_ISALNUM checks for an alphanumeric character.\n");
				printf("----------------------------------------------\n");
				printf("1st test - Checks for 'a'.\n");
				printf("1st test result: %d\n", ft_isalnum('a'));
				printf("2nd test - Checks for '@'.\n");
				printf("2nd test result: %d\n", ft_isalnum('@'));
				printf("3rd test - Checks for 48.\n");
				printf("3rd test result: %d\n", ft_isalnum(48));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 4:
				printf("FT_ISASCII checks whether c is a 7-bit unsigned char value that fits into the ASCII char set.\n");
				printf("----------------------------------------------\n");
				printf("1st test - Checks for 'a'.\n");
				printf("1st test result: %d\n", ft_isascii('a'));
				printf("2nd test - Checks for '*'.\n");
				printf("2nd test result: %d\n", ft_isascii('*'));
				printf("3rd test - Checks for 128.\n");
				printf("3rd test result: %d\n", ft_isascii(128));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 5:
				printf("FT_ISPRINT checks for any printable char including space.\n");
				printf("----------------------------------------------\n");
				printf("1st test - Checks for 'a'.\n");
				printf("1st test result: %d\n", ft_isprint('a'));
				printf("2nd test - Checks for '\a'.\n");
				printf("2nd test result: %d\n", ft_isprint('\a'));
				printf("3rd test - Checks for 32.\n");
				printf("3rd test result: %d\n", ft_isprint(32));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 6:
				printf("FT_STRLEN calculate the length of a string.\n");
				printf("----------------------------------------------\n");
				printf("1st test - Ola, mundo 123.\n");
				printf("1st test result: %zu\n", ft_strlen("Ola, mundo 123."));
				printf("2nd test - \n\n\f\r\t");
				printf("2nd test result: %zu\n", ft_strlen("\n\n\f\r\t"));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 7:
				printf("FT_STRLCPY size bounded string copying.\n");
				printf("----------------------------------------------\n");
				printf("1st test - src[] = Ola, mundo! and dst isnt assigned.\n");
				char	*src1 = "Ola, mundo!";
				char	dst1[15];
				ft_strlcpy(dst1, src1, 12);
				printf("1st test result: %s\n", dst1);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 8:
				printf("FT_STRLCAT size bounded string concatenation.\n");
				printf("----------------------------------------------\n");
				printf("1st test - src[] = mundo! and dst[] = Ola, \n");
				char	src2[] = "mundo!";
				char	dst2[] = "Ola, ";
				ft_strlcat(dst2, src2, 12);
				printf("1st test result: %s\n", dst2);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 9:
				printf("FT_STRCHR locates the first ocurrence of the char in the string.\n");
				printf("----------------------------------------------\n");
				printf("1st test - string[] = Ola, munda!\n");
				const char	s1[] = "Ola, munda!";
				printf("1st test result': %s\n", ft_strchr(s1, 'a'));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 10:
				printf("FT_STRRCHR locates the last ocurrence of the char is the string.\n");
				printf("----------------------------------------------\n");
				printf("1st test - string[] = Ola, munda!\n");
				const char	s2[] = "Ola, munda!";
				printf("1st test result: %s\n", ft_strrchr(s2, 'a'));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 11:
				printf("FT_STRNCMP compares two strings.\n");
				printf("----------------------------------------------\n");
				printf("1st test - a1[] = Ola, mundo! and a2[] = Ola, mundo!\n");
				char	a1[] = "Ola, mundo!";
				char	a2[] = "Ola, mundo!";
				printf("1st test result: %d\n", ft_strncmp(a1, a2, 11));
				printf("2nd test - b1[] = Ola,mundo! and b2[] = Ola, mundo!\n");
				char	b1[] = "Ola,mundo!";
				char	b2[] = "Ola, mundo!";
				printf("2nd test result: %d\n", ft_strncmp(b1, b2, 11));
				printf("3rd test - c1[] = Ola, mundo! and c2[] = Ola,mundo!\n");
				char	c1[] = "Ola, mundo!";
				char	c2[] = "Ola,mundo!";
				printf("3rd test result: %d\n", ft_strncmp(c1, c2, 11));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 12:
				printf("FT_STRNSTR locates a substring in a string.\n");
				printf("----------------------------------------------\n");
				printf("1st test- string[] = Foo Bar Baz and substring[] = Bar\n");
				const char	*bigstring = "Foo Bar Baz";
				const char	*lilstring = "Bar";
				printf("1st test result: %s\n", ft_strnstr(bigstring, lilstring, 3));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 13:
				printf("FT_ATOI converts a string to an integer.\n");
				printf("----------------------------------------------\n");
				printf("1st test - nptr[] = 123Ola.\n");
				const char	nptr[] = "123Ola";
				printf("1st test result: %d\n", ft_atoi(nptr));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 14:
				printf("FT_TOUPPER converts to upper case.\n");
				printf("----------------------------------------------\n");
				printf("1st test - converts int = 77.\n");
				printf("1st test result: %d\n", ft_toupper(77));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 15:
				printf("FT_TOLOWER converts to lower case.\n");
				printf("----------------------------------------------\n");
				printf("1st test - converts int = 15.\n");
				printf("1st test result: %d\n", ft_tolower(15));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 16:
				printf("FT_BZERO zeros a byte string.\n");
				printf("----------------------------------------------\n");
				printf("1st test - s[] = Ola, mundo! and n = 3.\n");
				char	s3[] = "Ola, mundo!";
				size_t n = 3;
				ft_bzero(s3, n);
				printf("1st test result: %s\n", s3);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 17:
				printf("FT_MEMSET fills memory with a constant byte.\n");
				printf("----------------------------------------------\n");
				printf("1st test - s[] = Ola, mundo!, c = 3 and n = 3\n");
				printf("2nd test - s[] = Ola, mundo!, c = 'c' and n = 5\n");
				char	s4[] = "Ola, mundo!";
				char	t[] = "Ola, mundo!";
				ft_memset(s4, 3, 3);
				printf("1st test result: %s\n", s4);
				ft_memset(t, 'c', 5);
				printf("2nd test result: %s\n", t);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 18:
				printf("FT_MEMCPY copy memory area.\n");
				printf("----------------------------------------------\n");
				printf("1st test - s[] = Hello, World and d[] = Ola, mundo!\n");
				char	s5[] = "Hello, World";
				char	d1[] = "Ola, mundo!";
				ft_memcpy(d1, s5, 6);
				printf("1st test result: %s\n", d1);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 19:
				printf("FT_MEMMOVE copy memory area.\n");
				printf("----------------------------------------------\n");
				printf("1st test - s[] = Ola, mundo!, d[] = Hello, bro! and n = 6.\n");
				char	s6[] = "Ola, mundo!";
				char	d2[] = "Hello, bro!";
				printf("String before ft_memmove: %s\n", d2);
				ft_memmove(d2, s6, 6);
				printf("String after ft_memmove: %s\n", d2);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 20:
				printf("FT_MEMCHR scans memory for a char.\n");
				printf("----------------------------------------------\n");
				printf("1st test - s[] = Ola, mundo!, c = 97 and n = 10.\n");
				char	s7[] = "Ola, mundo!";
				char	*r = ft_memchr(s7, 97, 10);
				printf("1st test result: %s\n", r);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 21:
				printf("FT_MEMCMP compares memory areas.\n");
				printf("----------------------------------------------\n");
				printf("1st test - s1[] = Ola, mundo!, s2[] = Ola, mundo! and n = 9\n");
				char	s8[] = "Ola, mundo!";
				char	s9[] = "Ola, mundo!";
				printf("1st test result: %d\n", ft_memcmp(s8, s9, 9));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 22:
				printf("FT_CALLOC alloc memory for an array and the memory is set to zero.\n");
				printf("----------------------------------------------\n");
				printf("1st test - calloc(4, size)\n");
				char	*re = ft_calloc(4, sizeof(int));
				for(int i = 0; i < 4; i++)
				{
					re[i] = i;
					printf("1st test result: %d\n", re[i]);
					i++;
				}
				free(re);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 23:
				printf("FT_STRDUP duplicates a string.\n");
				printf("----------------------------------------------\n");
				printf("1st test - s1[] = Duplicate me!!\n");
				const char	*s10 = "Duplicate me!!";
				printf("Duplicated string: %s\n", ft_strdup(s10));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 24:
				printf("FT_SUBSTR returns a substring from a string.\n");
				printf("----------------------------------------------\n");
				char	s11[] = "The string from which to create the substring.";
				char	*ss = ft_substr(s11, 4, 6);
				printf("The substring: %s\n", ss);
				free(ss);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 25:
				printf("FT_STRJOIN string concatenation.\n");
				printf("----------------------------------------------\n");
				char const	*s12 = "Ola, ";
				const char	*s13 = "mundo!";
				char	*s14 = ft_strjoin(s12, s13);
				printf("Joint string: %s\n", s14);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 26:
				printf("FT_STRTRIM string concatenation.\n");
				printf("----------------------------------------------\n");
				printf("Trimmed string: %s\n", ft_strtrim("Ola, mundo!!!", "la,"));
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 27:
				printf("FT_STRMAPI applies the function f to each char of s.\n");
				printf("----------------------------------------------\n");
				char	*input = "hello world";
				char	*output = ft_strmapi(input, addindex);
				printf("Input: %s\n", input);
				printf("Output: %s\n", output);
				free(output);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 28:
				printf("FT_STRITERI applies the function f to each char of s.\n");
				printf("----------------------------------------------\n");
				char	input2[] = "hello world";
				printf("Input: %s\n", input2);
				ft_striteri(input2, printchar);
				printf("Modified string: %s\n", input2);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 29:
				printf("FT_PUTCHAR_FD Outputs the char ’c’ to the given fd.\n");
				printf("----------------------------------------------\n");
				char	s15[] = "hello world";
				int	w = 0;
				while (s15[w])
				{
					ft_putchar_fd(s15[w], 1);
					w++;
				}
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 30:
				printf("FT_PUTSTR_FD Outputs the string to the given fd.\n");
				printf("----------------------------------------------\n");
				char	s16[] = "hello world";
				ft_putstr_fd(s16, 1);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 31:
				printf("FT_PUTENDL_FD Outputs s.\n");
				printf("----------------------------------------------\n");
				char	s17[] = "hello world";
				ft_putendl_fd(s17, 1);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 32:
				printf("FT_PUTNBR_FD Outputs the integer to the given fd.\n");
				printf("----------------------------------------------\n");
				ft_putnbr_fd(-2147483648, 1);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 33:
				printf("FT_SPLIT returns an array of strings delimited by c.\n");
				printf("----------------------------------------------\n");
				char const      string[] = "ccchelloccworldccolacmundoccc";
				char    delimiter = 'c';
				char    **tab = ft_split(string, delimiter);
				for (int i = 0; i < 4; i++)
				{
					int     j = 0;
					while (j < 5)
					{
                        printf("%c", tab[i][j]);
                        j++;
					}
					printf("\n");
				}
				if (!tab)
					return (0);
		        free(tab);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
			case 34:
				printf("FT_ITOA returns a string representing n.\n");
				printf("----------------------------------------------\n");
				char	*string;
				string = ft_itoa(-2147483647);
				printf("String: %s\n", string);
				free(string);
				printf("----------------------------------------------\n");
				printf("----------------------------------------------\n");
				i++;
				break;
		}
	}
	return (0);
}
