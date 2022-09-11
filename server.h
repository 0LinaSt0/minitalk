/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:52:36 by msalena           #+#    #+#             */
/*   Updated: 2021/09/03 21:52:36 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_str
{
	int		bit_count;
	int		arr_count;
	char	output_temp;
	char	input_str[4096];
}			t_str;

t_str	g_InStr;

void	struct_Initial(void);
void	server_PID(void);
void	ft_malloc(int fl);

void	sigusrs(int sig);
void	shaping_N_printing_str(void);

#endif

