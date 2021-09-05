/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:10:45 by msalena           #+#    #+#             */
/*   Updated: 2021/09/03 22:10:46 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *des, int c, size_t n)
{
	size_t			i;
	unsigned char	*z;

	i = 0;
	z = (unsigned char *) des;
	while (i < n)
	{
		z[i] = (unsigned char) c;
		i++;
	}
	return (z);
}
