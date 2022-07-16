#include <stdlib.h>

void fill_board(char *board);
int	conflict(int **parameters, char **board, int n);

void find_in_params(int params, int param_dir, int param_index, int *posdir)
{
	posdir[2] = (param_dir == 2) * 1 + (param_dir == 3) * -1;
	posdir[3] = (param_dir == 0) * 1 + (param_dir == 1) * -1;
	posdir[0] = param_index * (param_dir <= 1);
	posdir[1] = param_index * (param_dir >= 2);
	if(posdir[2] < 0)
		posdir[0] = 3;
	if(posdir[3] < 0)
		posdir[1] = 3;
}

void rm_from_cell(char *cell, char *list)
{
	int i;

	i = 0;
	while (list[i])
	{
		cell[list[i] - '1'] = 0;
		i++;
	}
}

int idx_from_posdir(int *posdir, int times)
{
	int res;

	res = (posdir[1] + posdir[3] * times) * 16;
	res += (posdir[0] + posdir[2] * times) * 4;
	return (res);
}

int first_pass(int **params, char *board)
{
	int i;
	int j;
	int posdir[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(params[i][j] == 4)
			{
				find_in_params(params[i][j], i, 4, posdir);
				rm_from_cell(&board[idx_from_posdir(posdir, 0)], "234");
				rm_from_cell(&board[idx_from_posdir(posdir, 1)], "134");
				rm_from_cell(&board[idx_from_posdir(posdir, 2)], "124");
				rm_from_cell(&board[idx_from_posdir(posdir, 3)], "123");
			}
			if(params[i][j] == 3)
			{	
			    find_in_params(params[i][j], i, 3, posdir);
				rm_from_cell(&board[idx_from_posdir(posdir, 0)], "34");
				rm_from_cell(&board[idx_from_posdir(posdir, 1)], "4");
			}
			j++;
		}
		i++;
	}
	return (1);
}

int solver(int **parameters)
{
	char board[4][4][4];

	fill_board(board);
	first_pass(parameters, board);

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				printf("%d", board[i][j][k]);
			}
			printf(" ");
		}
		printf("\n");
	}
	return (0);
}
