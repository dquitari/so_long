/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:23:16 by dquitari          #+#    #+#             */
/*   Updated: 2023/04/24 17:01:36 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(long int n)
{
	long int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = n *(-1);
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*str_fill(long int num, int len, char *str)
{
	int	i;

	i = 1;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len - i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	num = (long)n;
	if (n < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	str = str_fill(num, len, str);
	return (str);
}
