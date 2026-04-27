/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinheir <fpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:38:42 by fpinheir          #+#    #+#             */
/*   Updated: 2026/04/22 21:40:35 by fpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/*the modified atoi returns the number of lines that
the text file *says* that it has, aka, the number
written in the first line, excluding the last three
characters, of course

if it returns zero, whatever function called it should
note that it means the map isnt valid

if it doesnt have enough characters before the newline,
to accomodate a number A=and the map identifiers,
limit will be less than or equal to zero, the loop
wont run and nb will be zero

Thinking of modifying it further to check if the number
written is bigger than int_max*/

unsigned int	ft_atoi_modif(char *str)
{
	int				limit;
	int				i;
	unsigned int	nb;

	limit = 0;
	while (str[limit] != '\n')
		limit++;
	nb = 0;
	i = 0;
	limit = limit - 3;
	while (i < limit)
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (0);
		nb = (nb * 10) + (str[i] - '0');
		if (nb > (2147483647))
			return (0);
		i++;
	}
	return (nb);
}

/*Here we built a function that parses the first line
to use the right characters to be the "vazio", "obstáculo" and "cheio"
which are the 3 last before the first '\n' thingy. using the same
logic i used on the modified atoi, only then jumping right to the
last 3 characters and returning them in the correct order 
because they will be the map subtitles.*/

char	*firstlineparse(char *map)
{
	int		limit;
	char	*subs;

	limit = 0;
	while (map[limit] != '\n')
		limit++;
	if (limit < 4)
		return (NULL);
	subs = malloc(4);
	if (!subs)
		return (NULL);
	subs[0] = map[limit - 3];
	subs[1] = map[limit - 2];
	subs[2] = map[limit - 1];
	subs[3] = '\0';
	return (subs);
}

/*parse_map here calls the usefull functions we made
 (like the modified atoi and the first line parse) 
 in order to fill up the structure we
 declared before and keep the flow up.*/

int	parse_map(char *mapbuffer, t_map *map)
{
	char	*subs;
	char	*mapstart;
	int		cols;

	cols = 0;
	mapstart = mapbuffer + first_strlen(mapbuffer) + 1;
	while (mapstart[cols] && mapstart[cols] != '\n')
		cols++;
	map->cols = cols;
	map->rows = ft_atoi_modif(mapbuffer);
	if (map->rows <= 0)
		return (1);
	subs = firstlineparse(mapbuffer);
	if (!subs)
		return (1);
	map->empty = subs[0];
	map->obstacle = subs[1];
	map->full = subs[2];
	free(subs);
	return (0);
}
