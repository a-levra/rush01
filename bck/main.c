/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:26:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/16 18:36:16 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	**handle_args(int argc, char **argv, int accept_size);
char	**solver(int **parameters);

int	error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char**argv)
{
	int	**parameters;
	char **board;
	int	width;
	int	height;

	parameters = handle_args(argc, argv, 0);
	if (!parameters)
		return (error());
	width = parameters[0][0];
	height = parameters[0][1];

	if (!solver(parameters + 1))
		return (error());
	return (0);
}
