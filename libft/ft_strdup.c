/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:39:35 by dquitari          #+#    #+#             */
/*   Updated: 2023/04/14 14:45:35 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;

	len = ft_strlen(str) + 1;
	p = malloc(len * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		ft_memcpy(p, str, len);
		return (p);
	}
}
