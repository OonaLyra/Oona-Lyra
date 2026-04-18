/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llyra-li <llyra-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:46:31 by llyra-li          #+#    #+#             */
/*   Updated: 2026/04/13 09:38:07 by llyra-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	isalphabet(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return (1);
	else if ((letter >= '0' && letter <= '9'))
		return (1);
	return (0);
}

char	full_str(int s, char l)
{
	if (s == 1 && (l >= 'a' && l <= 'z'))
		return (l - 32);
	else if (s == 1 && (l >= 'A' && l <= 'Z'))
		;
	else if (s == 0 && (l >= 'A' && l <= 'Z'))
		return (l + 32);
	else if (s == 0 && (l >= '0' && l <= '9'))
		;
	return (l);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	while (str[i] != '\0')
	{
		if (isalphabet(str[i]) == 1)
		{
			str[i] = full_str(s, str[i]);
			s = 0;
			i++;
		}
		else
		{
			if (s == 0)
				s = 1;
			i++;
		}
	}
	return (str);
}
