/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinheir <fpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 20:30:41 by fpinheir          #+#    #+#             */
/*   Updated: 2026/04/21 20:30:43 by fpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char buff[128];
    int  result;

    result = read(0, buff, 127);
    if (result < 0)
        write(1, "Error\n", 6);
    else
    {
        buff[result] = '\0';
        printf("\n%s\n", buff);
    }
}