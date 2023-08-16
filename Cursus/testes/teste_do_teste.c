
int     ft_countwords(char const *s, char c)
{
        int     i;
        int     countedwords;

        i = 0;
        countedwords = 0;
        while (s[i])
        {
                if (s[i] == c)
                {
                        while (s[i] == c)
                                i++;
                }
                else if (s[i] != c)
                {
                        countedwords++;
                        while (s[i] != c)
                                i++;
                }
        }
        return (countedwords);
}

void	ft_split(char const *s, char c)
{
        int             i;
        int             nwords;
        char    **tab;

        if (!s)
                return ;
        i = 0;
        nwords = ft_countwords(s, c);
        printf("Countwords: %d\n", nwords);
}


int     main()
{

	char const      string[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
    char    delimiter = ' ';
    ft_split(string, delimiter);
	return (0);
}
