#include <stdio.h>

char *ft_strrev(char *str)
{
	int	i;
	int 	j;
	char temp;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	printf("%d\n", j);
	while (i < j / 2)
	{
		temp = str[i];
		str[i] = str[j - 1 - i];
		str[j - 1 - i] = temp;
		i++;
	}
	return (str);
}

int main() {
    // Test case 1: Regular string
    char test_str1[] = "hello";
    printf("Original: %s\n", test_str1);
    ft_strrev(test_str1);
    printf("Reversed: %s\n", test_str1);

    // Test case 2: Empty string
    char test_str2[] = "";
    printf("Original: '%s'\n", test_str2);
    ft_strrev(test_str2);
    printf("Reversed: '%s'\n", test_str2);

    // Test case 3: String with one character
    char test_str3[] = "A";
    printf("Original: '%s'\n", test_str3);
    ft_strrev(test_str3);
    printf("Reversed: '%s'\n", test_str3);

    // Test case 4: String with spaces
    char test_str4[] = "a b c";
    printf("Original: '%s'\n", test_str4);
    ft_strrev(test_str4);
    printf("Reversed: '%s'\n", test_str4);

    // Test case 5: String with special characters
    char test_str5[] = "!@#$%^";
    printf("Original: '%s'\n", test_str5);
    ft_strrev(test_str5);
    printf("Reversed: '%s'\n", test_str5);

    // Test case 6: String with numbers
    char test_str6[] = "123456";
    printf("Original: '%s'\n", test_str6);
    ft_strrev(test_str6);
    printf("Reversed: '%s'\n", test_str6);

    // Test case 7: String with mixed characters
    char test_str7[] = "a1b2c3";
    printf("Original: '%s'\n", test_str7);
    ft_strrev(test_str7);
    printf("Reversed: '%s'\n", test_str7);

    return 0;
}
