#include <stdlib.h>
#include <unistd.h>

//TODO free memory in case of error
int make_board(char ***board)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		board[i] = malloc(sizeof(char *) * 4); 
		if(!board[i])
			return (0);
		j = 0;
		while (j < 4)
		{
			board[i][j] = malloc(sizeof(char) * 4);
			if (!board[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void fill_board(char ***board)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				board[i][j][k] = k + 1;
				k++;
			}
			j++;
		}
		i++;
	}
}

void print_cell(char *cell)
{
	int i;
	char res;

	i = 0;
	while (i < 4)
	{
		if (cell[i] != 0)
		{
			res = cell[i] + '0';
			write(1, &res, 1);
			return ;
		}
		i++;
	}
}

void print_board(char ***board)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			print_cell(board[i][j]);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
