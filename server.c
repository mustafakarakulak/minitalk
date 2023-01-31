/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:34:30 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/19 18:34:30 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	catch_signal(int signum, siginfo_t *siginfo, void *unused)
{
	static int	character = 0;
	static int	index = 7;
	int			c;

	(void)unused;
	if (signum == SIGUSR1)
		c = 1;
	else
		c = 0;
	character += c << index;
	if (index == 0)
	{
		write(1, &character, 1);
		character = 0;
		index = 7;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			ft_putstr("Sinyal Gönderme Hatası\n");
	}
	else
		index--;
}

int	main(void)
{
	struct sigaction	sinyal;

	ft_putstr("Server Pid => ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sinyal.sa_flags = SA_SIGINFO;
	sinyal.sa_sigaction = catch_signal;
	if (sigaction(SIGUSR1, &sinyal, 0) == -1)
		ft_putstr("Sinyal Hatası!");
	if (sigaction(SIGUSR2, &sinyal, 0) == -1)
		ft_putstr("Sinyal Hatası!");
	while (1)
		pause();
	return (0);
}
