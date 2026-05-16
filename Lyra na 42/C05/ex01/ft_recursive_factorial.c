/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_fatorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:23:31 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/20 14:13:17 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb -1));
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	int	i;
// 
// 	i = ft_recursive_factorial(5);
// 	printf("%d", i);
// }
