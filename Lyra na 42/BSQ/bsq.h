/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinheir <fpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:58:04 by fpinheir          #+#    #+#             */
/*   Updated: 2026/04/22 22:15:34 by fpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

unsigned int	ft_atoi_modif(char *str);
char			*firstlineparse(char *map);
char			*mapread(int map);
int				first_strlen(char *str);
int				parse_map(char *mapbuffer, t_map *map);
int				validate_map(char *mapbuffer, t_map *map);
char			**make_grid(int rows, int cols, char *map);
void			free_grid(char **grid, int rows);
void			fill_square(int *start, int size, t_map *map);
int				valid_square(int row, int col, t_map *map);
void			solver(t_map *map);

#endif
