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
#include <stdio.h>
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
	int		offset;

	offset = 0;
	while (map[offset] != '\n')
		offset++;
	grid = malloc(rows * sizeof (char *));
	i = 0;
	while (i < rows)
	{
		j = 0;
		grid[i] = malloc(cols * sizeof (char));
		while (j < cols)
		{
			grid[i][j] = map[(offset + 1) + (i * (cols + 1)) + j];
			j++;
		}
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
	int		size;
	int		i;

	size = 1;
	while ((row + size - 1) < (map->rows) && ((col + size - 1) < (map->cols)))
	{
		i = 0;
		while (i < size)
		{
			if ((map->grid)[row + i][col] == (map->obstacle))
				return (size);
			if ((map->grid)[row][col + i] == (map->obstacle))
				return (size);
			i++;
		}
		if ((map->grid)[row + size - 1][col + size - 1] == (map->obstacle))
			return (size);
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
