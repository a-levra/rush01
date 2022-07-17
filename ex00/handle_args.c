/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:21:51 by alevra            #+#    #+#             */
/*   Updated: 2022/07/17 18:26:08 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	char_is_valid_number(char c);
int	char_is_space(char c);
int	ft_strlen(char *str);
int	check_and_copy(char *str, int **params);

int	**handle_args(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;
	int				**params;
	void			*error;

	error = NULL;
	i = 0;
	j = 0;
	if (argc != 2)
		return (error);
	params = malloc(sizeof(int *) * 4);
	while (i < 4)
		params[i++] = malloc(sizeof(int) * 4);
	i = 0;
	if (ft_strlen(argv[1]) != 31)
		return (error);
	if (!check_and_copy(argv[1], params))
		return (error);
	return (params);
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
			if (!(char_is_space(str[i])))
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

int	char_is_space(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}
