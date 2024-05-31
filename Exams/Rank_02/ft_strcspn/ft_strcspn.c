
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
		j++;
		}
		i++;
	}
	return (i);
}

int	main()
{
	size_t	len_bytes;

	len_bytes = strcspn("ola, meu mano!", "meu");
	printf("Original function: %zu\n", len_bytes);
	printf("My function: %zu\n", ft_strcspn("ola, meu mano!", "meu"));
	return (0);
}
