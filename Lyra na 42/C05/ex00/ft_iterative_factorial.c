/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:29:13 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/20 13:28:32 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	v;

	i = nb;
	v = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i > 0)
	{
		v = v * i;
		i--;
	}
	return (v);
}

// #include <stdio.h>
//
//int	main(void)
//{
//	int	i;
//
//	i = ft_iterative_factorial(5);
//	printf("%d", i);
//}
//