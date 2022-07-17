/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:27:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/17 16:28:15 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rm_from_cell(char *cell, char *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		cell[list[i] - '1'] = 0;
		i++;
	}
}

void	set_cell(char *cell, char value)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (i != value)
			cell[i - 1] = 0;
		else
			cell[i - 1] = value;
		i++;
	}
}

char	*get_cell(char ***board, int *posdir, int times)
{
	int	x;
	int	y;

	x = posdir[0] + posdir[2] * times;
	y = posdir[1] + posdir[3] * times;
	return (board[y][x]);
}

int	is_cell_certain(char *cell)
{
	int	count;
	int	res;
	int	i;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (cell[i] != 0)
		{
			res = cell[i];
			count++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (res);
}

void	print_cell(char *cell)
{
	int		i;
	char	res;

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
