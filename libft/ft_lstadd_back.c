/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:38:48 by dquitari          #+#    #+#             */
/*   Updated: 2023/05/05 15:38:49 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_walk_list **lst, t_walk_list *new)
{
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
	}
	else
		ft_lstlast(*lst)->next = new;
}
