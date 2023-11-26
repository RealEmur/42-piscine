#include <unistd.h>

int	is_safe_square(char board[10][10], int row_index, int column_index)
{
	int		temp_column_right;
	int		temp_column_left;

	temp_column_right = column_index;
	temp_column_left = column_index;
	while (row_index >= 0)
	{
		if (board[row_index][column_index])
			return (0);
		else if (temp_column_left >= 0 && board[row_index][temp_column_left])
			return (0);
		else if (temp_column_right < 10 && board[row_index][temp_column_right])
			return (0);
		row_index--;
		temp_column_left--;
		temp_column_right++;
	}
	return (1);
}

void	print_board(char board[10][10])
{
	int		row_index;
	int		column_index;
	char	chr;

	row_index = 0;
	column_index = 0;
	while (row_index < 10)
	{
		column_index = 0;
		while (column_index < 10)
		{
			if (board[row_index][column_index] == 1)
			{
				chr = column_index + '0';
				write(1, &chr, 1);
				break ;
			}
			column_index++;
		}
		row_index++;
	}
	write(1, "\n", 1);
}

void	add_queen(char board[10][10], int row_index, int *count)
{
	int		column_index;

	if (row_index >= 10)
	{
		print_board(board);
		*count = *count + 1;
		return ;
	}
	column_index = 0;
	while (column_index < 10)
	{
		if (is_safe_square(board, row_index, column_index))
		{
			board[row_index][column_index] = 1;
			add_queen(board, row_index + 1, count);
			board[row_index][column_index] = 0;
		}
		column_index++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10][10];
	int		row_index;
	int		column_index;
	int		count;

	row_index = 0;
	column_index = 0;
	while (row_index < 10)
	{
		column_index = 0;
		while (column_index < 10)
		{
			board[row_index][column_index] = 0;
			column_index++;
		}
		row_index++;
	}
	count = 0;
	add_queen(board, 0, &count);
	return (count);
}
