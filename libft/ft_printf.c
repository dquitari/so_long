/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:40:20 by dquitari          #+#    #+#             */
/*   Updated: 2023/05/29 13:40:24 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_classify(va_list arg_list, const char *str, int i)
{
	if (str[i] == 'c')
		return (ft_print_char(va_arg(arg_list, int)));
	else if (str[i] == 's')
		return (ft_print_str(va_arg(arg_list, char *)));
	else if (str[i] == 'p')
		return (ft_print_ptr(va_arg(arg_list, unsigned long long)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_print_nbr(va_arg(arg_list, int)));
	else if (str[i] == 'u')
		return (ft_print_unbr(va_arg(arg_list, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (ft_print_hex(va_arg(arg_list, unsigned int), str[i]));
	else if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		i;
	int		special;

	if (!str || *str == '\0')
		return (-1);
	i = 0;
	special = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			special++;
		}
		else if (str[i + 1] != '\0')
			special += ft_classify(arg_list, str, ++i);
		i++;
	}
	va_end(arg_list);
	return (special);
}

/*int	main()
{
	char a = 0;

	//my function
	ft_printf("a %c %x %X a\n", '2', a, a);
	//standard function
	printf("a %c %x %X a\n", '2', a, a);
	return (0);
}*/
