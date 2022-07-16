/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:26:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/16 07:05:02 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	**handle_args(int argc, char **argv, int accept_size);

int	error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char**argv)
{
	int	**board;
	int	width;
	int	height;

	board = handle_args(argc, argv, 1);
	if (!board)
		return (error());
	width = board[0][0];
	height = board[0][1];

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < board[0][i / 2]; j++)
		{
			printf("%d ", board[i + 1][j]);
		}
		printf("\n");
	}

	return (0);
}
