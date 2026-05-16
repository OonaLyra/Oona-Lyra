/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:43:14 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/22 18:43:14 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Strlen, but just for the first line of the file
// so its more of a first_line_len.
int	first_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

/*This will look up on the info we filled on the map structure, and if there are
any discrepancies, will write "map error" and return (1).*/
int	validate_map(char *mapbuffer, t_map *map)
{
	int		current_leng;
	int		row_count;
	char	*s;
	int		first_len;

	first_len = first_strlen(mapbuffer);
	current_leng = 0;
	row_count = 0;
	 if (mapbuffer[first_len] == '\0') // Se não tem nem a primeira linha completa
        return (1);
        
	s = mapbuffer + first_len + 1;
	while (*s)
	{
		if (*s == '\n')
		{
			if (current_leng != map->cols)
				return (1);
			row_count++;
			current_leng = -1;
		}
		else if (*s != map->empty && *s != map->obstacle)
			return (1);
		current_leng++;
		s++;
	}
	if (current_leng != 0)
		return (1);
	return (row_count != map->rows);
}
