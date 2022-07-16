/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_parameters_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:17:33 by alevra            #+#    #+#             */
/*   Updated: 2022/07/16 14:19:13 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdio.h>

int	value_is_valid(int value, int side_size);

int	are_parameters_valid(int **visible_boxes, int width, int height)
{
	int	side;
	int	j;
	int	side_size;

	side = 0;
	while (side <= 4)
	{
		j = 0;
		if (side == 0 || side == 1)
			side_size = width;
		else
			side_size = height;
		while (j < side_size)
		{
			if (!(value_is_valid(visible_boxes[side][j], side_size)))
			{
				return (0);
			}
			j++;
		}
		side++;
	}
	return (1);
}

int	value_is_valid(int value, int side_size)
{
	if (value >= 1 && value <= side_size)
		return (1);
	return (0);
}
