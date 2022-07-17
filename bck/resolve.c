/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:25:11 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/17 16:25:59 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		is_cell_certain(char *cell);
void	rm_from_col_row(char ***board, int x, int y, char value);
void	set_cell(char *cell, char value);

int	rm_impossible(char ***board)
{
	int		i;
	int		j;
	int		loop;
	char	value;

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

void	add_occurences(char *cell, char *count)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cell[i])
			count[i]++;
		i++;
	}
}

void	resolve_line(char ***board, int y, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[y][i][value - 1])
			set_cell(board[y][i], value);
		i++;
	}
}

void	resolve_col(char ***board, int x, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[i][x][value - 1])
			set_cell(board[i][x], value);
		i++;
	}
}

void	calc_posdir(int param_dir, int param_index, int *posdir)
{
	posdir[2] = (param_dir == 2) * 1 + (param_dir == 3) * -1;
	posdir[3] = (param_dir == 0) * 1 + (param_dir == 1) * -1;
	posdir[0] = param_index * (param_dir <= 1);
	posdir[1] = param_index * (param_dir >= 2);
	if (posdir[2] < 0)
		posdir[0] = 3;
	if (posdir[3] < 0)
		posdir[1] = 3;
}
