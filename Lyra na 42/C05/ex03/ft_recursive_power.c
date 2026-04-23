/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:23:08 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/20 23:46:08 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, (power - 1)));
}

//	#include <stdio.h>
//	
//	int	main(void)
//	{
//		printf("%d", ft_recursive_power(2, 4));
//		return (0);
//	}