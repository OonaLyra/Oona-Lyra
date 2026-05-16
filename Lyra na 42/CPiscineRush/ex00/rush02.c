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
extern void	ft_putchar(char c);

int	rush(int y, int x)
{
	int	v;
	int	h;

	if (y <= 0 || x <= 0)
	{
		return (0);
	}
	v = 0;
	while (++v <= y)
	{
		h = 0;
		while (++h <= x)
		{
			if (v == 1 && (h == 1 || h == x))
				(ft_putchar('A'));
			else if (v == y && (h == 1 || h == x))
				(ft_putchar('C'));
			else if (h == 1 || h == x || v == 1 || v == y)
				(ft_putchar('B'));
			else
				(ft_putchar(' '));
		}
		ft_putchar('\n');
	}
	return (0);
}
