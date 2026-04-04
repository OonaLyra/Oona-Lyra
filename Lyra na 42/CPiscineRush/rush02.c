/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:45:34 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/04 16:45:34 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

extern void	ft_putchar(char c);

int	rush(int vert, int hori)
{
	int	v;
	int	h;

	v = 1;
	h = 1;
	while (v <= vert)
	{
		while (h <= hori)
		{
			if (h == 1 || h == hori)
			{
				if (v == 1)
				{
					ft_putchar('A');
				}
				else if (v == vert)
				{
					ft_putchar('C');
				}
				else
				{
					ft_putchar('B');
				}
			}
			else
			{
				if (v == 1 || v == vert)
				{
					ft_putchar('B');
				}
				else
				{
					ft_putchar(' ');
				}
			}
			h++;
		}
		h = 1;
		v++;
		ft_putchar('\n');
	}
		return (0);
	}
