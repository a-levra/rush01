/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:26:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/17 06:56:17 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**handle_args(int argc, char **argv);
int	solver(int **parameters, char ***board);
int make_board(char ***board);
void fill_board(char ***board);
void print_board(char ***board);

int	error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char**argv)
{
	int	**parameters;
	char ***board;

	board = 0;
	parameters = handle_args(argc, argv);
	if (!parameters)
		return (error());
	board = malloc(sizeof(char **) * 4);
	if (!board)
		return (error());
	if (!make_board(board))
		return (error());
	fill_board(board);
	if (!solver(parameters + 1, board))
		return (error());
	print_board(board);
	return (0);
}
