/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:10:30 by msalena           #+#    #+#             */
/*   Updated: 2021/09/03 22:10:31 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*kak;

	kak = (t_list *)malloc(sizeof(t_list));
	if (kak == NULL)
		return (NULL);
	kak->content = content;
	kak->next = NULL;
	return (kak);
}
