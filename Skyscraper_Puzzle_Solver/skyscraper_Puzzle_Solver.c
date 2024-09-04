/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkarada <abkarada@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:49:12 by abkarada          #+#    #+#             */
/*   Updated: 2024/07/13 14:49:15 by abkarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define N 4

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_grid(int grid[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < N - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	is_valid(int grid[N][N], int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < N)
	{
		if (grid[row][x] == num || grid[x][col] == num)
			return (0);
		x++;
	}
	return (1);
}

void	get_views(int *views, int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	i = 0;
	while (i < N * N)
	{
		views[i] = argv[1][i * 2] - '0';
		i++;
	}
}

int	check_views(int grid[N][N], int *views)
{
	int	top[N], bottom[N], left[N], right[N];
	int	col, row, i, max_seen, count;

	col = -1;
	while (++col < N)
	{
		max_seen = 0;
		count = 0;
		row = -1;
		while (++row < N)
		{
			if (grid[row][col] > max_seen)
			{
				max_seen = grid[row][col];
				count++;
			}
		}
		top[col] = count;
	}
	col = -1;
	while (++col < N)
	{
		max_seen = 0;
		count = 0;
		row = N;
		while (--row >= 0)
		{
			if (grid[row][col] > max_seen)
			{
				max_seen = grid[row][col];
				count++;
			}
		}
		bottom[col] = count;
	}
	row = -1;
	while (++row < N)
	{
		max_seen = 0;
		count = 0;
		col = -1;
		while (++col < N)
		{
			if (grid[row][col] > max_seen)
			{
				max_seen = grid[row][col];
				count++;
			}
		}
		left[row] = count;
	}
	row = -1;
	while (++row < N)
	{
		max_seen = 0;
		count = 0;
		col = N;
		while (--col >= 0)
		{
			if (grid[row][col] > max_seen)
			{
				max_seen = grid[row][col];
				count++;
			}
		}
		right[row] = count;
	}
	i = -1;
	while (++i < N)
	{
		if (views[i] != top[i] || views[i + N] != bottom[i] ||
			views[i + 2 * N] != left[i] || views[i + 3 * N] != right[i])
		{
			return (0);
		}
	}
	return (1);
}

int	solve(int grid[N][N], int row, int col, int *views)
{
	int	num;

	if (row == N - 1 && col == N)
	{
		return (check_views(grid, views));
	}
	if (col == N && ++row)
	{
		col = 0;
	}
	num = 0;
	while (++num <= N)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1, views))
			{
				return (1);
			}
			grid[row][col] = 0;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	views[N * N];
	int	grid[N][N] = {{0}};

	get_views(views, argc, argv);
	if (solve(grid, 0, 0, views))
	{
		print_grid(grid);
	}
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
} 
