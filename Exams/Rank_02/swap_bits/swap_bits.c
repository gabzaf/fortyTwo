
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) & (octet << 4));
}

int	main()
{
	printf("%u", swap_bits(0b01000001));
	return (0);
}
