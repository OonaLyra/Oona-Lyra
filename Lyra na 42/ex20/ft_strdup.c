/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:01:22 by llyra-li          #+#    #+#             */
/*   Updated: 2026/05/15 19:40:52 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int		t;

	t = 0;
	while (str[t] != '\0')
	{
		t++;
	}
	return (t);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	ft_strcpy(dest, src);
	return (dest);
}
