/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:29:40 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/16 13:16:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi(char **str);
int		contains_other_than(char *str, char *search);
void	free_array(int **array, int size);
int		ft_is_white_space(char c);

int	get_size(char *arg, int *width, int *height)
{
	if (!arg)
	{
		*width = 4;
		*height = 4;
		return (1);
	}
	*width = ft_atoi(&arg);
	*height = ft_atoi(&arg);
	if (*width <= 0 || *height <= 0)
		return (0);
	return (1);
}

int	get_parameters(int **parameters, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < parameters[0][i / 2])
		{
			parameters[i + 1][j] = ft_atoi(&str);
			if (!parameters[i + 1][j])
				return (0);
			j++;
		}
		i++;
	}
	while (*str)
		if (!ft_is_white_space(*str++))
			return (0);
	return (1);
}

int	make_parameters(int **parameters)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		parameters[i + 1] = malloc(sizeof(int) * parameters[0][i / 2]);
		if (!parameters[i + 1])
		{
			free_array(parameters, 5);
			return (0);
		}
		i++;
	}
	return (1);
}

int	**get_data(char *arg, int width, int height)
{
	int	**res;
	int	i;

	res = malloc(sizeof(int *) * 5);
	if (!res)
		return (0);
	res[0] = malloc(sizeof(int) * 2);
	if (!res[0])
	{
		free_array(res, 5);
		return (0);
	}
	res[0][0] = width;
	res[0][1] = height;
	i = 0;
	if (!make_parameters(res))
		return (0);
	if (!get_parameters(res, arg))
		return (0);
	return (res);
}

int	**handle_args(int argc, char **argv, int accept_size)
{
	int	width;
	int	height;
	int	i;

	i = 1;
	while (i < argc)
		if (contains_other_than(argv[i++], "0123456789 "))
			return (0);
	if (accept_size && argc == 3)
	{
		if (!get_size(argv[2], &width, &height))
			return (0);
	}
	else if (argc == 2)
	{
		if (!get_size(0, &width, &height))
			return (0);
	}
	else
		return (0);
	return (get_data(argv[1], width, height));
}
