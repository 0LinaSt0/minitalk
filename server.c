/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:52:32 by msalena           #+#    #+#             */
/*   Updated: 2021/09/05 15:40:54 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	struct_Initial(void)
{
	g_InStr.bit_count = 0;
	g_InStr.output_temp = 0;
	g_InStr.arr_count = 0;
}

/* print server PID in terminal */
void	server_PID(void)
{
	pid_t	PID;

	PID = getpid();
	ft_putendl_fd (ft_itoa(PID), 1);
}

void	sigusrs(int	sig)
{
	if (sig == SIGUSR1)
		g_InStr.output_temp |= (1 << g_InStr.bit_count);
	g_InStr.bit_count++;
}

void	shaping_N_printing_str(void)
{
	if (g_InStr.bit_count == 8)
	{
		if (g_InStr.arr_count == 4096)
		{
			ft_putstr_fd(g_InStr.input_str, 1);
			ft_bzero(g_InStr.input_str, 4096);
			g_InStr.arr_count = 0;
		}
		g_InStr.input_str[g_InStr.arr_count] = g_InStr.output_temp;
		g_InStr.bit_count = 0;
		g_InStr.output_temp = 0;
		g_InStr.arr_count++;
		if (g_InStr.input_str[g_InStr.arr_count - 1] == '\0')
		{
			ft_putendl_fd(g_InStr.input_str, 1);
			g_InStr.arr_count = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sig1;
	struct sigaction	sig2;

	sig1.__sigaction_u.__sa_handler = sigusrs;
	sig2.__sigaction_u.__sa_handler = sigusrs;
	struct_Initial();
	server_PID ();
	while (1)
	{
		sigaction(SIGUSR1, &sig1, 0);
		sigaction(SIGUSR2, &sig2, 0);
		shaping_N_printing_str ();
		pause ();
	}
}
