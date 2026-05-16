/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:39:33 by llyra-li          #+#    #+#             */
/*   Updated: 2026/05/11 17:50:35 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	l;
	int		i;

	l = 'a';
	i = 1;
	while (i <= 26)
	{
		ft_putchar(l);
		l++;
		i++;
	}
}
