/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:26:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/17 21:21:52 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	handle_args(int argc, char **argv, int ***params);
int		solver(int **parameters, char ***board);
int		make_board(char ***board);
void	fill_board(char ***board);
void	print_board(char ***board);

void	free_board(char ***board)
{
	int	i;
	int	j;

	if (!board)
		return ;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			free(board[i][j]);
			j++;
		}
		free(board[i]);
		i++;
	}
	free(board);
}

void	free_params(int	**params)
{
	int	i;

	if (!params)
		return ;
	i = 0;
	while (i < 4)
	{
		free(params[i]);
		i++;
	}
	free(params);
}

int	error(int **params, char ***board)
{
	write(1, "Error\n", 6);
	free_board(board);
	free_params(params);
	return (1);
}

int	main(int argc, char**argv)
{
	int		**parameters;
	char	***board;

	board = 0;
	handle_args(argc, argv, &parameters);
	if (!parameters)
		return (error(parameters, board));
	board = malloc(sizeof(char **) * 4);
	if (!board)
		return (error(parameters, board));
	if (!make_board(board))
		return (error(parameters, board));
	fill_board(board);
	if (!solver(parameters, board))
		return (error(parameters, board));
	print_board(board);
	free_board(board);
	free_params(parameters);
	return (0);
}
