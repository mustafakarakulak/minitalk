/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:38:13 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/18 19:26:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_binary_to_char(int c)
{
	static int	i = 7;
	static int	character = 0;

	character += c << i;
	if (i == 0)
	{
		i = 7;
		write(1, &character, 1);
		character = 0;
	}
	else
		i--;
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		convert_binary_to_char(1);
	else if (sig == SIGUSR2)
		convert_binary_to_char(0);
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	write(1, "Server Pid : ", 13);
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
