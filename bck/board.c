#include <stdlib.h>

void fill_board(char *board)
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
				board[i * 16 + j * 4 + k] = k + 1;
				k++;
			}
			j++;
		}
		i++;
	}
}
