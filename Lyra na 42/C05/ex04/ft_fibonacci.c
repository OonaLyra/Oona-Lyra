/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:30:59 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/20 22:41:52 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	v1;
	int	v2;
	int	temp;

	if (index == 0)
		return (0);
	if (index < 0)
		return (-1);
	v1 = 1;
	v2 = 0;
	while (index > 1)
	{
		temp = v1;
		v1 = v2 + v1;
		v2 = temp;
		index--;
	}
	return (v1);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	printf("%d", ft_fibonacci(11));
// 	return (0);
// }
// 