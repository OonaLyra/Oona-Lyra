/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:02:53 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/23 13:04:32 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	t;

	t = 0;
	while (str[t] != 0)
	{
		write(1, &str[t], 1);
		t++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i >= (1))
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
