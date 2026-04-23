/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:51:44 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/19 17:24:51 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	obt_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	baselen(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	sinal;

	sinal = 1;
	nb = 0;
	i = 0;
	while (base[i])
		i++;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sinal *= -1;
		str++;
	}
	while (obt_value(*str, base) != -1)
	{
		nb = (nb * baselen(base)) + obt_value(*str, base);
		str++;
	}
	return (nb * sinal);
}
