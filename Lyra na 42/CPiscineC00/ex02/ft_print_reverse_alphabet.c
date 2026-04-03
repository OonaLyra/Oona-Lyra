/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:43:31 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/02 14:43:36 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	alfabetorevertido[26];

	i = 0;
	while (i < 26)
	{
		alfabetorevertido[i] = 'z' - i;
		i++;
	}
	write(1, alfabetorevertido, 26);
}
