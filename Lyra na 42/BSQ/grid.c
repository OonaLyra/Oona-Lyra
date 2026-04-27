/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinheir <fpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 20:32:05 by fpinheir          #+#    #+#             */
/*   Updated: 2026/04/22 22:42:24 by fpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"

/*
This functions creates and initializes a grid to put the map's info
first it iterates up to right after the first \n, where the "intro" ends,
and then allocates array of strings, which makes parsing the map
looking for the biggest square waaaay easier. 
*/

char	**make_grid(int rows, int cols, char *map)
{
	char	**grid;
	int		i;
	int		j;
	char	*curr;

	curr = map;
	while (*curr && *curr != '\n')
		curr++;
	if (*curr == '\n')
		curr++;
	grid = malloc(rows * sizeof (char *));
	i = 0;
	/* In theory it should be working now, without segfauls since
	we've not only increased the buffer size from 128kb to 1mb but also
	we're trying another way to work with the offset on the lines and cols;*/
	while (i < rows)
	{
		j = 0;
		grid[i] = malloc(cols * sizeof (char));
		while (j < cols && *curr && *curr != '\n')
		{
			grid[i][j] = *curr;
			curr++;
			j++;
		}
		if (*curr == '\n')
			curr++;
		i++;
	}
	return (grid);
}

void	free_grid(char **grid, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	fill_square(int *start, int size, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			(map->grid)[start[0] + i][start[1] + j] = (map->full);
			j++;
		}
		i++;
	}
	return ;
}

int	valid_square(int row, int col, t_map *map)
{
	int	size;
	int	i;

	size = 1;
	while ((row + size) < map->rows && (col + size) < map->cols)
	{
		i = 0;
		while (i <= size)
		{
			if (map->grid[row + size][col + i] == map->obstacle ||
				map->grid[row + i][col + size] == map->obstacle)
				return (size);
			i++;
		}
		size++;
	}
	return (size);
}

void	solver(t_map *map)
{
	int	row;
	int	col;
	int	max_square;
	int	max_start[2];
	int	cur_square;

	max_square = 0;
	max_start[0] = 0;
	max_start[1] = 0;
	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < (map->cols))
		{
			cur_square = valid_square(row, col, map);
			if (cur_square > max_square)
			{
				max_start[0] = row;
				max_start[1] = col;
				max_square = cur_square;
			}
			col++;
		}
		row++;
	}
	fill_square(max_start, max_square, map);
}
