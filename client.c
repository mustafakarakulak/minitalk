/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:21:26 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/18 19:26:53 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_character_bits(int c, int pid)
{
	int				i;
	unsigned char	message_c;

	message_c = c;
	i = 128;
	while (i)
	{
		if (message_c / i >= 1)
		{
			message_c %= i;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(95);
		i /= 2;
	}
}

void	send_message(char *message, int pid)
{
	while (*message)
	{
		send_character_bits(*message, pid);
		message++;
	}
	send_character_bits('\n', pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_message(message, pid);
		return (1);
	}
	else
		write(1, "ERROR: ./client <pid> message\n", 31);
	return (0);
}
