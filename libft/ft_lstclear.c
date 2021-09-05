/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:10:20 by msalena           #+#    #+#             */
/*   Updated: 2021/09/03 22:10:21 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save_nexts;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		save_nexts = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = save_nexts;
	}
}
