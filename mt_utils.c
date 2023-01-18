/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:32:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/18 12:41:31 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_itoa(int pid)
{
	char	c;

	if (pid >= 10)
		ft_itoa(pid / 10);
	c = (pid % 10) + 48;
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int	number;

	number = 0;
	while (*str)
		number = (10 * number) + (*str++ - 48);
	return (number);
}
