/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:21:51 by alevra            #+#    #+#             */
/*   Updated: 2022/07/17 21:20:57 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	free_array(int **array);
int		char_is_valid_number(char c);
int		ft_strlen(char *str);
int		check_and_copy(char *str, int **params);

int	handle_args(int argc, char **argv, int ***params)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	if (argc != 2)
		return (0);
	*params = malloc(sizeof(int *) * 4);
	while (++i)
		(*params)[i] = 0;
	i = -1;
	if (!(*params))
		return (0);
	while (++i < 4)
	{
		(*params)[i] = malloc(sizeof(int) * 4);
		if (!(*params)[i])
			return (0);
	}
	i = 0;
	if (ft_strlen(argv[1]) != 31)
		return (0);
	if (!check_and_copy(argv[1], *params))
		return (0);
	return (1);
}

int	check_and_copy(char *str, int **params)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(i % 2))
		{
			if (char_is_valid_number(str[i]))
			{
				params[j / 4][j % 4] = str[i] - '0';
				j++;
			}
			else
				return (0);
		}
		else
			if (str[i] != ' ')
				return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i ++;
		str++;
	}
	return (i);
}

int	char_is_valid_number(char c)
{
	if (c >= '1' && c <= '4' )
		return (1);
	else
		return (0);
}

void	free_array(int **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (++i < 4)
		if (array[i])
			free(array[i]);
	free(array);
}
