/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:35:41 by llyra-li          #+#    #+#             */
/*   Updated: 2026/05/13 16:28:32 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_sort_arrays(int argc, char **argv)
{
	char	*buf;
	int		i;

	i = 1;
	while (i < argc)
	{
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				buf = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = buf;
			}
			i++;
		}
		i = 1;
		argc--;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	char	**mod;
	int		i;

	mod = ft_sort_arrays(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		if (i < argc - 1)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
