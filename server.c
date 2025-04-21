/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:28 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/21 15:17:34 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signals(int signum)
{
	int		bit_pos;
	char	curr_char;

	bit_pos = 0;
	curr_char = 0;
	if (signum == SIGUSR2)
		curr_char |= (0 << bit_pos);
	else if (signum == SIGUSR1)
		curr_char |= (1 << bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		ft_printf("%c", curr_char);
		bit_pos = 0;
		curr_char = 0;
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
