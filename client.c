/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:52:38 by msalena           #+#    #+#             */
/*   Updated: 2022/09/11 16:50:53 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

/* transmission binary string to server */
void	sig_transmission(char *str_argv, char **argv)
{
	size_t	i_str;
	int		i_char;
	pid_t	pid;

	i_str = 0;
	i_char = 0;
	pid = ft_atoi (*(argv + 1));
	while (i_str <= ft_strlen (str_argv))
	{
		while (i_char <= 7)
		{
			if (((str_argv[i_str] >> i_char) & 0x01) == 1)
				kill (pid, SIGUSR1);
			else if (((str_argv[i_str] >> i_char) & 0x01) == 0)
				kill (pid, SIGUSR2);
			i_char++;
			usleep(105);
		}
		i_char = 0;
		i_str++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*point;

	if (argc < 2)
	{
		write(1, "error: please, give me more arguments\n", 39);
		return 1;
	}
	i = 2;
	point = *(argv + i);
	while (point)
	{
		sig_transmission (point, argv);
		i++;
		point = *(argv + i);
	}
}
