#include <stdio.h>

char	to_lower(char c)				//Convert a character to lowercase
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));		//convert to lowercase and return
	return (c);
}

int	get_digit(char c, int digits_in_base)		//Get digit value in given base
{
	int	max_digit;

	if (digits_in_base <= 10)			//check if base is less than or equal to 10
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';	//calculate maximum digit value for base > 10
	if (c >= '0' && c <= '9' && c <= max_digit) 	//check if character is a digit within valid range
		return (c - '0');			//convert digit character to integer and return
	else if (c >= 'a' && c <= 'f' && c <= max_digit)//check if character is a letter between 'a' and 'f'
		return (10 + c - 'a');			//convert letter character to integer and return
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)	//Define function to convert string to integer in given base
{
	int	r;
	int	sign;
	int	digit;

	r = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0) //loop through string characters until invalid character or end of string
	{
		r *= str_base;				//multiply result by base
		r += (digit * sign);			//add digit value to result, taking sign into account
		++str;
	}
	return (r);
}

/*int	main(void)
{
	//Test ft_atoi_base with hexadecimal input "1A", expected output: 26
	printf("%d\n", ft_atoi_base("C04", 16));
	//Test ft_atoi_base with binary input "1011", expected output: 11
	//printf("%d\n", ft_atoi_base("1011", 2));
	//Test ft_atoi_base with octal input "123", expected output: 83
	//printf("%d\n", ft_atoi_base("123", 8)); 
	//Test ft_atoi_base with decimal input "-42", expected output: 42
	//printf("%d\n", ft_atoi_base("-42", 10));     
	//Test ft_atoi_base with decimal input "0123", expected output: 27 
	//printf("%d\n", ft_atoi_base("0123", 4)); 
	return (0);
}*/
