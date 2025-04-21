/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:28 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/21 15:36:50 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	g_byte;

void	handle_signals(int signum)
{
	static int		bit_pos;
	
	if (signum == SIGUSR1)
		g_byte |= (1 << (7 - bit_pos));
	else if (signum == SIGUSR2)
		g_byte &= ~(1 << (7 - bit_pos));
	
	bit_pos++;
	if (bit_pos == 8)
	{
		ft_printf("%c", g_byte);
		bit_pos = 0;
		g_byte = 0;
	}
}

int	main(void)
{
	struct	sigaction sa;

	g_byte = 0;
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handle_signals;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Failed to set SIGUSR1 handler\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Failed to set SIGUSR2 handler\n");
		return (1);
	}

	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
