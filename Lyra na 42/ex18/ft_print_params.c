/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:57:09 by llyra-li          #+#    #+#             */
/*   Updated: 2026/05/12 13:10:07 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	l;

	l = 1;
	while (l < argc != '\0')
	{
		i = 0;
		while (argv[l][i] != '\0')
		{
			ft_putchar(argv[l][i]);
			i++;
		}
		ft_putchar('\n');
		l++;
	}
	return (0);
}