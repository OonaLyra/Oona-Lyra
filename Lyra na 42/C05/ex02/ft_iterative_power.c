/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:58:19 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/21 18:37:48 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nbr;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	nbr = 1;
	while (power > 0)
	{
		nbr = nbr * nb;
		power--;
	}
	return (nbr);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	printf("%d", ft_iterative_power(2, 10));
// 	return (0);
// }
