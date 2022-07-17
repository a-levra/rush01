/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:13:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/17 16:20:34 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_cell_certain(char *cell);
void	rm_from_cell(char *cell, char *list);
void	set_cell(char *cell, char value);
char	*get_cell(char ***board, int *posdir, int times);

void	rule_4(char ***board, int i, int j, int *posdir);
void	rule_3(char ***board, int i, int j, int *posdir);
void	rule_1(char ***board, int i, int j, int *posdir);
void	rule_1_2(char ***board, int i, int j, int *posdir);
void	rule_2_2_end(char ***board, int i, int j, int *posdir);
void	rule_3_2_end(char ***board, int i, int j, int *posdir);

int		rm_impossible(char ***board);
void	add_occurences(char *cell, char *count);
void	resolve_line(char ***board, int y, int value);
void	resolve_col(char ***board, int x, int value);
void	calc_posdir(int param_dir, int param_index, int *posdir);

void	rm_from_col_row(char ***board, int x, int y, char value);

int	first_pass(int **params, char ***board)
{
	int	i;
	int	j;
	int	posdir[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (params[i][j] == 4)
				rule_4(board, i, j, posdir);
			if (params[i][j] == 3)
				rule_3(board, i, j, posdir);
			if (params[i][j] == 1)
				rule_1(board, i, j, posdir);
			if (params[i][j] == 1 && params[(i + 1) % 2 + (i / 2) * 2][j] == 2)
				rule_1_2(board, i, j, posdir);
			j++;
		}
		i++;
	}
	return (1);
}

void	second_pass(char ***board)
{
	int		i;
	int		j;
	char	count_possible[8];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 8)
			count_possible[j] = 0;
		j = -1;
		while (++j < 4)
		{
			add_occurences(board[i][j], count_possible);
			add_occurences(board[j][i], count_possible + 4);
		}
		j = -1;
		while (++j < 8)
		{	
			if (count_possible[j] == 1 && j < 4)
				resolve_line(board, i, j % 4 + 1);
			else if (count_possible[j] == 1 && j >= 4)
				resolve_col(board, i, j % 4 + 1);
		}
	}
}

void	last_pass(int **params, char ***board)
{
	int	i;
	int	j;
	int	posdir[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (params[i][j] == 2 && params[(i + 1) % 2 + (i / 2) * 2][j] == 2)
				rule_2_2_end(board, i, j, posdir);
			if (params[i][j] == 3 && params[(i + 1) % 2 + (i / 2) * 2][j] == 2)
				rule_3_2_end(board, i, j, posdir);
			j++;
		}
		i++;
	}
}

int	is_solution_valid(char ***board)

{
	int		i;
	int		j;
	char	value;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			value = is_cell_certain(board[i][j]);
			if (!value)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	solver(int **parameters, char ***board)
{
	first_pass(parameters, board);
	rm_impossible(board);
	second_pass(board);
	rm_impossible(board);
	second_pass(board);
	rm_impossible(board);
	last_pass(parameters, board);
	rm_impossible(board);
	return (is_solution_valid(board));
}
