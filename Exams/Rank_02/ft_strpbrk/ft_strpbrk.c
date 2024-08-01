#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	while(*s1)
	{
		i = 0;
	   	while(s2[i])
		{
			if(*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}

/*int main() {
    // Test cases
    const char *test_str1 = "hello world";
    const char *test_str2 = "1rd";
    const char *test_str3 = "abc";

    // Test 1: Common characters
    char *result = ft_strpbrk(test_str1, test_str2);
    printf("Test 1: %s\n", result ? result : "No match");

    // Test 2: No common characters
    result = ft_strpbrk(test_str1, test_str3);
    printf("Test 2: %s\n", result ? result : "No match");
    return 0;
}*/
