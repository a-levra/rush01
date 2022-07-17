/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:28:19 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/17 16:29:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print_cell(char *cell);
void	rm_from_cell(char *cell, char *list);

void	rm_from_col_row(char ***board, int x, int y, char value)
{
	int		i;
	char	to_rm[2];

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

int	make_board(char ***board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		board[i] = malloc(sizeof(char *) * 4);
		if (!board[i])
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

void	fill_board(char ***board)
{
	int	i;
	int	j;
	int	k;

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

void	print_board(char ***board)
{
	int	i;
	int	j;

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
