/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:34:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/19 18:34:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int signum, unsigned char *message)
{
	int	i;
	int	c;

	c = 0;
	i = 128;
	while (message[c] != '\0')
	{
		while (i >= 1)
		{
			if (message[c] / i)
			{
				kill(signum, SIGUSR1);
				message[c] = message[c] % i;
			}
			else
				kill(signum, SIGUSR2);
			usleep(100);
			i /= 2;
		}
		i = 128;
		c++;
	}
}

void	catch_signal(int signum, siginfo_t *siginfo, void *unused)
{
	static int	first_time = 1;

	(void)signum;
	(void)siginfo;
	(void)unused;
	if (first_time)
	{
		ft_putstr("Mesaj başarıyla gönderildi!\n");
		first_time = 0;
	}
}

int	main(int arg, char **argc)
{
	struct sigaction	signal;
	int					p_id;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = catch_signal;
	if ((sigaction(SIGUSR2, &signal, 0)) == -1)
		ft_putstr("Sinyal Gönderme Hatası\n");
	if (arg == 3)
	{
		p_id = ft_ascii_toint(argc[1]);
		send_signal(p_id, (unsigned char *)argc[2]);
	}
	else
		ft_putstr("./clinet <pid> [message]");
	return (0);
}
