#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != accept[j] && accept[j] != '\0')
			j++;
		if (accept[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

/*int main(void)
{
	const char	*str1 = "Hello, world!";
	const char	*ch1 = "ello, ";
	size_t	result = ft_strspn(str1, ch1);
	
	printf("%ld\n", result);
	printf("%ld\n", strspn(str1, ch1));
	return (0);
}*/
