#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str, int *length)
{
	if (!str)
		str = "(null)";
       while (*str)
		*length += write(1, str++, 1);	       
}

void	ft_putnbr(long long int nbr, int base, int *length)
{
	if (nbr < 0)
	{
		nbr *= -1;
		*length += write(1, "-", 1);
	}
	if (nbr >= base)
		ft_putnbr((nbr / base), base, length);
	*length += write(1, &("0123456789abcdef"[nbr % base]), 1);
}

int	ft_printf(const char *fmt, ...)
{
	int	length = 0;
	va_list	pntr;

	va_start(pntr, fmt);
	while (*fmt)
	{
		if ((*fmt == '%') && ((*(fmt + 1) == 's') || (*(fmt + 1) == 'd') || (*(fmt + 1) == 'x')))
		{
			fmt++;
			if (*fmt == 's')
				ft_putstr(va_arg(pntr, char *), &length);
			else if (*fmt == 'd')
				ft_putnbr((long long int)va_arg(pntr, int), 10, &length);
			else if (*fmt == 'x')
				ft_putnbr((long long int)va_arg(pntr, unsigned int), 16, &length);
		}
		else
			length = length + write(1, fmt, 1);
		fmt++;
	}
	return (va_end(pntr), length);
}
