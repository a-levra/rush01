int count_box_vertical(char **board, int direction, int height, int offset)
{
	int i;
	int max;
	int count;

	count = 0;
	max = 0;
	i = 0;
	if (direction == 1)
		i = height - 1;
	while (i < height && i >= 0)
	{
		if (board[i][offset] > max)
		{
			count++;
			max = board[i][offset];
		}
		i += (direction == 1) * -2 + 1;
	}
	return (count);
}

int count_box_horizontal(char **board, int direction, int height, int offset)
{
	int i;
	int max;
	int count;

	count = 0;
	max = 0;
	i = 0;
	if (direction == 3)
		i = height - 1;
	while (i < height && i >= 0)
	{
		if (board[offset][i] > max)
		{
			count++;
			max = board[offset][i];
		}
		i += (direction == 3) * -2 + 1;
	}
	return (count);
}

int conflict_column(char **board, int height, int offset)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = i + 1;
		while (j < height)
			if (board[i][offset] == board[j++][offset])
				return (1);
		i++;
	}
	return (0);
}

int conflict_line(char **board, int width, int offset)
{
	int i;
	int j;

	i = 0;
	while (i < width)
	{
		j = i + 1;
		while (j < width)
			if (board[offset][i] == board[offset][j++])
				return (1);
		i++;
	}
	return (0);
}

int	conflict(int **parameters, char **board, int n)
{
	/*int i;
	int j;
	int k;

	i = 0;
	while (i < n)
	{
		if (conflict_column(board, parameters[0][1], i))
			return (1);
		if (conflict_line(board, parameters[0][0], n))
			return (1);
		if (count_box_vertical(board, 0, parameters[0][1], i) != parameters[1][i])
			return (1);
		if (count_box_vertical(board, 1, parameters[0][1], i) != parameters[2][i])
			return (1);
	}
	i = 0;
	while (i < parameters[0][1] && n == parameters[0][0])
	{
		
	}*/
	return (0);
}
