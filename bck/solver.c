#include <stdlib.h>

int is_cell_certain(char *cell);
void rm_from_cell(char *cell, char *list);
void set_cell(char *cell, char value);
char *get_cell(char ***board, int *posdir, int times);

void rule_4(char ***board, int i, int j, int *posdir);
void rule_3(char ***board, int i, int j, int *posdir);
void rule_1(char ***board, int i, int j, int *posdir);
void rule_1_2(char ***board, int i, int j, int *posdir);
void rule_2_2_end(char ***board, int i, int j, int *posdir);
void rule_3_2_end(char ***board, int i, int j, int *posdir);

void calc_posdir(int param_dir, int param_index, int *posdir)
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

int first_pass(int **params, char ***board)
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
				rule_4(board, i, j, posdir);
			if(params[i][j] == 3)
				rule_3(board, i, j, posdir);
			if(params[i][j] == 1)
				rule_1(board, i, j, posdir);
			if(params[i][j] == 1 && params[(i + 1) % 2 + i / 2][j] == 2)
				rule_1_2(board, i, j, posdir);
			j++;
		}
		i++;
	}
	return (1);
}


void rm_from_col_row(char ***board, int x, int y, char value)
{
	int i;
	char to_rm[2];

	to_rm[0] = value + '0';
	to_rm[1] = '\0';
	i = 0;
	while (i < 4)
	{
		if (i != x)
			rm_from_cell(board[y][i], to_rm);
		if (i != y)
			rm_from_cell(board[i][x], to_rm);
		i++;
	}
}

int rm_impossible(char ***board)
{
	int i;
	int j;
	int loop;
	char value;

	loop = 0;
	while (loop++ < 3)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				value = is_cell_certain(board[i][j]);
				if (value)
					rm_from_col_row(board, j, i, value);
				j++;
			}
			i++;
		}
	}
	return (1);
}

void add_occurences(char *cell, char *count)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (cell[i])
			count[i]++;
		i++;
	}
}

void resolve_line(char ***board, int y, int value)
{
	int i;

	printf("line: y = %d, value = %d\n", y, value);
	i = 0;
	while (i < 4)
	{
		if (board[y][i][value - 1])
			set_cell(board[y][i], value);
		i++;
	}
}

void resolve_col(char ***board, int x, int value)
{
	int i;

	printf("col: x = %d, value = %d\n", x, value);
	i = 0;
	while (i < 4)
	{
		if (board[i][x][value - 1])
			set_cell(board[i][x], value);
		i++;
	}
}

void second_pass(char ***board)
{
	int i;
	int j;
	char *count_possible;

	count_possible = malloc(sizeof(char) * 8);
	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 8)
			count_possible[j] = 0;
		j = 0;
		
		while (j < 4)
		{
			add_occurences(board[i][j], count_possible);
			add_occurences(board[j][i], count_possible + 4);
			j++;
		}
		printf("count for i = %d : ", i);
		for(int a = 0; a < 8; a++)
			printf("%d ", count_possible[a]);
		printf("\n");
		j = 0;
		while (j < 8)
		{	
			if (count_possible[j] == 1)
			{
				if (j < 4)
					resolve_line(board, i, j % 4 + 1);
				else
					resolve_col(board, i, j % 4 + 1);
			}
			j++;
		}
		i++;
	}
	free(count_possible);
}

void last_pass(int **params, char ***board)
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
			if(params[i][j] == 2 && params[(i + 1) % 2 + i / 2][j] == 2)
				rule_2_2_end(board, i, j, posdir);
			if(params[i][j] == 3 && params[(i + 1) % 2 + i / 2][j] == 2)
				rule_3_2_end(board, i, j, posdir);

			j++;
		}
		i++;
	}
}

int is_solution_valid(char ***board)
{
	int i;
	int j;
	char value;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			value = is_cell_certain(board[i][j]);
			if(!value)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

#include <stdio.h>

int solver(int **parameters, char ***board)
{
	first_pass(parameters, board);
	rm_impossible(board);
	second_pass(board);
	rm_impossible(board);
	second_pass(board);
	rm_impossible(board);
	last_pass(parameters, board);
	rm_impossible(board);

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
				printf("%d", board[i][j][k]);
			printf(" ");
		}
		printf("\n");
	}

	return (is_solution_valid(board));
}
