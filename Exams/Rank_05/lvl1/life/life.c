#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pen
{
	int	x;
	int	y;
	int	isdown;
} pen;

char	**create_board(int w, int h)
{
	char	**b = (char **)malloc(sizeof(char *) * h);
	for (int j = 0; j < h; j++)
	{
		b[j] = (char *)malloc(sizeof(char) * w);
		for (int i = 0; i < w; i++)
			b[j][i] = ' ';
	}
	return (b);
}

void	free_board(char **b, int h)
{
	for (int i = 0; i < h; i++)
		free(b[i]);
	free(b);
}

int	count_n(char **b, int w, int h, int x, int y)
{
	int c = 0;
	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			if (!(j == 0 && i == 0) && j + y >= 0 && j + y < h && i + x >= 0 && i + x < w && (b[j + y][i + x] == '0'))
				c++;
		}
	}
	return (c);
}

void	iter_game(char **b, int w, int h)
{
	char	**clone = create_board(w, h);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int	c = count_n(b, w, h, x, y);
			if ((b[y][x] == '0' && (c == 2 || c == 3)) || (b[y][x] != '0' && c == 3))
				clone[y][x] = '0';
			else
				clone[y][x] = ' ';
		}
	}
	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++)
			b[j][i] = clone[j][i];
	}
	free_board(clone, h);
}

void	print_board(char **b, int w, int h)
{
	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++)
			putchar(b[j][i]);
		putchar('\n');
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	int	w = atoi(av[1]), h = atoi(av[2]), iter = atoi(av[3]);
	pen	p = {0, 0, 0};
	int	c = 0;
	char	**board = create_board(w, h);

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			p.isdown = !p.isdown;
		if (c == 'w' && p.y > 0)
			p.y--;
		if (c == 'a' && p.x > 0)
			p.x--;
		if (c == 's' && p.y < h - 1)
			p.y++;
		if (c == 'd' && p.x < w - 1)
			p.x++;
		if (p.isdown)
			board[p.y][p.x] = '0';
	}
	for (int i = 0; i < iter; i++)
		iter_game(board, w, h);
	print_board(board, w, h);
	free_board(board, h);
	return (0);
}
