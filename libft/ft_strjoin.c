/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:14:08 by dquitari          #+#    #+#             */
/*   Updated: 2023/10/26 18:14:12 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*nstash;

	i = 0;
	j = 0;
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	nstash = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!nstash)
		return (NULL);
	while (stash[i])
	{
		nstash[i] = stash[i];
		i++;
	}
	while (buffer[j])
		nstash[i++] = buffer[j++];
	nstash[i] = '\0';
	free(stash);
	return (nstash);
}
