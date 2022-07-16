/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:30:28 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/16 10:53:24 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(void **array, int size)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < size)
		if (array[i])
			free(array[i]);
	free(array);
}
