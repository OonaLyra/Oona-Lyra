/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:09:02 by llyra-li          #+#    #+#             */
/*   Updated: 2026/05/15 20:42:45 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*s;
	int	i;

	i = 0;
	if (max <= min)
		return (NULL);
	s = malloc((max - min) * sizeof (int));

	while (i < (max - min))
	{
		s[i] = min + i;
		i++;
	}
	if (s == NULL)
		return (NULL);
	return (s);
}
