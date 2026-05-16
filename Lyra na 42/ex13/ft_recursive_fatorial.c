/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_fatorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:58:50 by llyra-li          #+#    #+#             */
/*   Updated: 2026/05/12 12:04:43 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int n)
{
	if (n <= 1)
		return (1);
	else
		return (n * ft_recursive_factorial(n - 1));
}
