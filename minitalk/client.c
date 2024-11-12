/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:24 by adimas-d          #+#    #+#             */
/*   Updated: 2024/11/07 16:58:37 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct t_info	g_info;

void	send_next_bit(void)
{
	static int		i;
	static int		bit;
	unsigned char	ch;

	ch = g_info.msg[i];
	if (i > g_info.len)
		return ;
	g_info.msg[i] = ch >> 1;
	bit++;
	if (bit == 32)
	{
		bit = 0;
		i++;
	}
	if (ch & 0x01)
		kill(g_info.pid_received, SIGUSR2);
	else
		kill(g_info.pid_received, SIGUSR1);
}

void	ft_bit_ack(int signal)
{
	(void)signal;
	write(1, "!", 1);
	send_next_bit();
}

void	ft_msg_ack(int signal)
{
	(void)signal;
	write(1, "\nMessage receved! Thank you!\n", 29);
	exit(0);
}

int	main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac != 3)
		return (0);
	while (av[1][i])
	{
		if (!(ft_isdigit(av[1][i])))
			return (0);
		i++;
	}
	g_info.pid_received = ft_atoi(av[1]);
	if (g_info.pid_received <= 0)
		return (0);
	g_info.msg = av[2];
	if (signal(SIGUSR1, ft_bit_ack) == SIG_ERR)
		exit(1);
	if (signal(SIGUSR2, ft_msg_ack) == SIG_ERR)
		exit(1);
	g_info.len = ft_strlen(g_info.msg);
	send_next_bit();
	while (1)
		pause();
	return (0);
}
