/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinheir <fpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:30 by fpinheir          #+#    #+#             */
/*   Updated: 2026/04/22 22:33:04 by fpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//i dunno if i gotta free the buffer in the case of
//malloc not working (buffer = NULL)

char	*mapread(int fd_map)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(131072 * sizeof (char));
	if (!buffer)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	bytes = read(fd_map, buffer, 131071);
	if (bytes < 0)
	{
		free(buffer);
		write(1, "map error\n", 10);
		return (0);
	}
	buffer[bytes] = '\0';
	return (buffer);
}

void	resolve(t_map *map, char *buffer)
{
	int	i;
	int	j;

	map->grid = make_grid(map->rows, map->cols, buffer);
	solver(map);
	i = 0;
	while (i < (map->rows))
	{
		j = 0;
		while (j < (map->cols))
		{
			write(1, &(map->grid)[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	free_grid(map->grid, map->rows);
}

//A function to take off all the workload of
// validating maps that is currently on the main

int	is_map_okay(int fd_map)
{
	char	*mapbuffer;
	t_map	map;

	if (fd_map < 0)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	mapbuffer = mapread(fd_map);
	close(fd_map);
	if (!mapbuffer)
		return (1);
	if (parse_map(mapbuffer, &map) || validate_map(mapbuffer, &map))
	{
		free(mapbuffer);
		write(1, "map error\n", 10);
		return (1);
	}
	resolve(&map, mapbuffer);
	free(mapbuffer);
	return (0);
}

void	get_from_terminal(void)
{
	char	buffer[100];
	int		bytes;
	int		map;

	bytes = read(0, buffer, 99);
	if (bytes < 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	buffer[bytes] = '\0';
	map = open(buffer, O_RDONLY);
	if (map < 0)
		write(1, "map error\n", 10);
	else
	{
		is_map_okay(map);
	}
}

/*Just a simple main with the purpose of resolving some of the functions
will not be the final main tho. not it has some space*/

int	main(int argc, char **argv)
{
	int		map;
	int		i;

	if (argc == 1)
	{
		get_from_terminal();
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map = open(argv[i], O_RDONLY);
			if (map < 0)
				write(1, "map error\n", 10);
			else
			{
				is_map_okay(map);
			}
			if (i != (argc - 1))
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
