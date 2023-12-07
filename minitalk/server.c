/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:48 by adimas-d          #+#    #+#             */
/*   Updated: 2023/12/04 17:35:51 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_signal_handler(int signal, siginfo_t *si, void *unused)
{
	static int	bit = 0;
	static int	print = 0;

	(void)unused;
	if (signal == SIGUSR2)
		print += (1 << bit);
	if (bit++ == 31)
	{
		if (print == '\0')
		{
			write(1, "\n", 1);
			kill(si->si_pid, SIGUSR2);
		}
		else
			ft_putchar_fd (print, 1);
		bit = 0;
		print = 0;
	}
	kill(si->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig_handler;

	sig_handler.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_handler.sa_mask);
	sig_handler.sa_sigaction = ft_signal_handler;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sig_handler, NULL);
	sigaction(SIGUSR2, &sig_handler, NULL);
	while (1)
	{
		sleep(1);
	}
}
