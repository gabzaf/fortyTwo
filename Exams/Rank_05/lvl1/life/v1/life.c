#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct pen
{
	int x;
	int y;
	int isdown;
} pen;

char	**create_board(int w, int h)
{
	char	**b = (char **)malloc(sizeof(char *) * h);
	for (int i = 0; i < h; i++)
	{
		b[i] = (char *) malloc(sizeof(char *) * w);
		for (int j = 0; j < w; j++)
			b[i][j] = ' ';
	}
	return (b);
}

void	print_board(char **b, int w, int h)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			putchar(b[i][j]);
		putchar('\n');
	}
}

void	free_board(char **b, int h)
{
	for (int i = 0; i < h; i++)
		free(b[i]);
	free(b);
}

int	count(char **b, int w, int h, int x, int y)
{
	int c = 0;
	for (int i = - 1; i <= 1; i++)
	{
		for (int j = - 1; j <= 1; j++)
		{
			if (!(i == 0 && j == 0) && 
					i + y >= 0 && i + y < h &&
					j + x >= 0 && j + x < w &&
					(b[i + y][j + x] == '0'))
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
			int c = count(b, w, h, x, y);
			if ((b[y][x] == '0' &&
					(c == '2' || c == '3')) ||
					(b[y][x] != '0' && c == '3'))
				clone[y][x] = '0';
			else
				clone[y][x] = ' ';
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			b[i][j] = clone[i][j];
	}
	free_board(clone, h);
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
