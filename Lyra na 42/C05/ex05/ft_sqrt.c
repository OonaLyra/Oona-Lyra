/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:44:28 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/20 23:45:51 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while ((i * i) < nb)
		i++;
	if (i * i == nb)
		return ((int)i);
	return (0);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	printf("%d", ft_sqrt(16));
// 	return (0);
// }