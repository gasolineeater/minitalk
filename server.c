/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:28 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/21 15:07:39 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct	sigaction sa;
	int 	id;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	id = getpid();
	ft_printf("Server PID: %d\n", id);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
