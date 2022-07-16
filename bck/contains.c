/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:29:58 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/16 05:30:00 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	contains_chr(char *str, char chr)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == chr)
			return (1);
	return (0);
}

int	contains_other_than(char *str, char *search)
{
	int	i;

	i = 0;
	while (str[i])
		if (!contains_chr(search, str[i++]))
			return (1);
	return (0);
}
