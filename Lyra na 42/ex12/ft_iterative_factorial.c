/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:10:15 by llyra-li          #+#    #+#             */
/*   Updated: 2026/05/12 11:52:34 by llyra-li         ###   ########.fr       */
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
	while (i > 1)
	{
		v = v * i;
		i--;
	}
	return (v);
}
