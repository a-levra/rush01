/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:24:35 by ldurieux          #+#    #+#             */
/*   Updated: 2022/07/17 16:25:01 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	rm_from_cell(char *cell, char *list);
char	*get_cell(char ***board, int *posdir, int times);
void	calc_posdir(int param_dir, int param_index, int *posdir);

void	rule_4(char ***board, int i, int j, int *posdir)
{
	char	*cell;

	calc_posdir(i, j, posdir);
	cell = get_cell(board, posdir, 0);
	rm_from_cell(cell, "234");
	cell = get_cell(board, posdir, 1);
	rm_from_cell(cell, "134");
	cell = get_cell(board, posdir, 2);
	rm_from_cell(cell, "124");
	cell = get_cell(board, posdir, 3);
	rm_from_cell(cell, "123");
}

void	rule_3(char ***board, int i, int j, int *posdir)
{
	char	*cell;

	calc_posdir(i, j, posdir);
	cell = get_cell(board, posdir, 0);
	rm_from_cell(cell, "34");
	cell = get_cell(board, posdir, 1);
	rm_from_cell(cell, "4");
}

void	rule_1(char ***board, int i, int j, int *posdir)
{
	char	*cell;

	calc_posdir(i, j, posdir);
	cell = get_cell(board, posdir, 0);
	rm_from_cell(cell, "123");
}

void	rule_1_2(char ***board, int i, int j, int *posdir)
{
	char	*cell;

	calc_posdir(i, j, posdir);
	cell = get_cell(board, posdir, 3);
	rm_from_cell(cell, "124");
}
