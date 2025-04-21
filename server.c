/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:28 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/21 15:24:31 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	g_byte;

void	handle_signals(int signum)
{
	static int		bit_pos;

	bit_pos = 0;
	if (signum == SIGUSR1)
		g_byte |= (1 <<(7 - bit_pos));
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
	int 	id;

	sa.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	id = getpid();
	ft_printf("Server PID: %d\n", id);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
