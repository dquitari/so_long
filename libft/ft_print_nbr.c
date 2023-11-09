/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:19:14 by dquitari          #+#    #+#             */
/*   Updated: 2023/06/06 11:19:15 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	ft_put_nbr(int n)
{
	if (n < 0)
	{
		ft_putchar_fd(('-'), 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_put_nbr(n / 10);
		ft_put_nbr(n % 10);
	}
	else
		ft_putchar_fd((n + '0'), 1);
}

int	ft_print_nbr(int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	else if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
		ft_put_nbr(n);
	return (ft_nbr_len(n));
}
