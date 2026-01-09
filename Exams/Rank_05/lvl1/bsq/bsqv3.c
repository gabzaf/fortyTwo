#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_bsq
{
	int	lines;
	int	width;
	char	empt;
	char	obs;
	char	full;
	char	**map;
} t_bsq;

#define ERROR "Error: invalid map \n"

FILE	*open_input(char *av)
{
	FILE	*file = av ? fopen(av, "r") : stdin;
	if (!file)
		fputs(ERROR, stdout), exit(1);
	return (file);
}

void	free_map(t_bsq *bsq, int i)
{
	for (int j = 0; j < i; j++)
		free(bsq->map[j]);
	free(bsq->map);
}

void	close_on_error(t_bsq *bsq, FILE *file, char *av, int i, char *line)
{
	if (line)
		free(line);
	if (av)
		fclose(file);
	fputs(ERROR, stdout);
	if (i >= 0)
		free_map(bsq, i);
	exit(1);
}

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	parse_header(t_bsq *bsq, FILE *file, char *av)
{
	if (fscanf(file, "%d%c%c%c\n", &bsq->lines, &bsq->empt, &bsq->obs, &bsq->full) != 4)
		close_on_error(bsq, file, av, -1, NULL);
	if (bsq->lines <= 0 || bsq->empt == bsq->obs || bsq->empt == bsq->full || bsq->obs == bsq->full)
	       close_on_error(bsq, file, av, -1, NULL);	
	printf("%d\n", bsq->lines);
}

void	allocate_map(t_bsq *bsq, FILE *file, char *av)
{
	bsq->map = (char **)malloc(sizeof(char *) * bsq->lines);
	if (!bsq->map)
		close_on_error(bsq, file, av, -1, NULL);
}

char	*read_line(t_bsq *bsq, FILE *file, char *av, int i)
{
	char	*line = NULL;
	size_t	len = 0;

	if (getline(&line, &len, file) == -1)
	{
		printf("cheguei aqui");
		close_on_error(bsq, file, av, i, line);
	}
	int	new_len = ft_strlen(line);
	if (new_len > 0 && line[new_len - 1] == '\n')
		line[new_len - 1] = '\0';
	else if (i < bsq->lines - 1 && line[new_len - 1] != '\n')
		close_on_error(bsq, file, av, i, line);
	return (line);
}

void	check_map(t_bsq *bsq)
{
	for (int i = 0; i < bsq->lines; i++)
		for (int j = 0; j < bsq->width; j++)
			if (bsq->map[i][j] != bsq->empt && bsq->map[i][j] != bsq->obs)
				free_map(bsq, bsq->lines), fputs(ERROR, stdout) ,exit(1);
}

void	parse_bsq(t_bsq *bsq, char *av)
{
	FILE	*file = open_input(av);
	parse_header(bsq, file, av);
	allocate_map(bsq, file, av);
	for (int i = 0; i < bsq->lines; i++)
	{
		char	*line = read_line(bsq, file, av, i);
		int	len = ft_strlen(line);
		if (i == 0)
			bsq->width = len;
		else if (i < bsq->lines - 1 && bsq->width != len)
			close_on_error(bsq, file, av, i, line);
		bsq->map[i] = line;
	}
	if (av)
		fclose(file);
	check_map(bsq);
}

int	min3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

void	solve_bsq(t_bsq *bsq)
{
	int	dp[bsq->lines][bsq->width];
	int	max = 0, b_i = 0, b_j = 0;

	for (int i = 0; i < bsq->lines; i++)
	{
		for (int j = 0; j < bsq->width; j++)
		{
			if (bsq->map[i][j] == bsq->obs)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j -1]) + 1;
			if (dp[i][j] > max)
			{
				max = dp[i][j];
				b_i = i;
				b_j = j;
			}
		}
	}
	int	st_i = b_i - max + 1;
	int	st_j = b_j - max + 1;
	int	f_i = st_i + max;
	int	f_j = st_j + max;

	for (int i = st_i; i < f_i; i++)
		for (int j = st_j; j < f_j; j++)
			bsq->map[i][j] = bsq->full;
}

void	print_map(t_bsq *bsq)
{
	for (int i = 0; i < bsq->lines; i++)
		printf("%s\n", bsq->map[i]);
}

int	main(int ac, char **av)
{
	t_bsq	bsq;

	if (ac == 1)
		parse_bsq(&bsq, NULL);
	else if (ac == 2)
		parse_bsq(&bsq, av[1]);
	else
		return (printf("Error: invalid number of args \n"), 1);
	solve_bsq(&bsq);
	print_map(&bsq);
	free_map(&bsq, bsq.lines);
	return (0);
}
