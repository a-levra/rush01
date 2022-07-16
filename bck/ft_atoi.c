/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:30:11 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/16 05:30:13 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_white_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char **str)
{
	int	negative;
	int	res;

	negative = 0;
	res = 0;
	while (ft_is_white_space(**str))
		(*str)++;
	while (ft_is_sign(**str))
	{
		if (**str == '-')
			negative = !negative;
		(*str)++;
	}
	while (ft_is_number(**str))
	{
		res = res * 10 + **str - '0';
		(*str)++;
	}
	if (negative)
		return (-res);
	return (res);
}
