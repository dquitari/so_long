/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:19:36 by dquitari          #+#    #+#             */
/*   Updated: 2023/06/06 11:19:37 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unbr_len(unsigned int unbr)
{
	int	len;

	len = 0;
	while (unbr != 0)
	{
		len++;
		unbr = unbr / 10;
	}
	return (len);
}

void	ft_put_unbr(unsigned int unbr)
{
	if (unbr >= 10)
	{
		ft_put_unbr(unbr / 10);
		ft_put_unbr(unbr % 10);
	}
	else
		ft_putchar_fd((unbr + '0'), 1);
}

int	ft_print_unbr(unsigned int unbr)
{
	if (unbr == 0)
		return (write(1, "0", 1));
	else
		ft_put_unbr(unbr);
	return (ft_unbr_len(unbr));
}
