#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	charcmp(char c1, char c2)
{
	return ((unsigned char)c1 - (unsigned char)c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (charcmp(s1[i], s2[i]) != 0)
			return (charcmp(s1[i], s2[i]));
		i++;
	}
	if (i < n)
		return (charcmp(s1[i], s2[i]));
	return (0);
}

int	check_filename(char *file)
{
	size_t len; 
	
	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (!(len <= 4 || ft_strncmp(file + len - 4, ".cub", 4) || !ft_strncmp(file + len - 5, "/.cub", 5)))
		return (1);
	return (0);
}

int	main(void)
{
	char *test_cases[] = {
		"map.cub",
		"level.cub",
		"world.txt",
		"test.cube",
		".cub",
		"game/.cub",
		"maps/game.cub",
		NULL
	};

	for (int i = 0; test_cases[i] != NULL; i++)
	{
		printf("File: %s -> check_filename: %d\n", test_cases[i], check_filename(test_cases[i]));
	}

	return (0);
}

