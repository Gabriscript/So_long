/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:59:01 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/21 11:49:36 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int	manage_conversion(char c, va_list args)
{
	if (c == 'c')
		return (manage_char(va_arg(args, int)));
	else if (c == 's')
		return (manage_string(va_arg(args, char *)));
	else if (c == 'p')
		return (manage_pointer(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (manage_integer(va_arg(args, int)));
	else if (c == 'u')
		return (manage_unsigned(va_arg(args, unsigned long long)));
	else if (c == 'x')
		return (manage_hex_lower(va_arg(args, unsigned long long)));
	else if (c == 'X')
		return (manage_hex_upper(va_arg(args, unsigned long long)));
	else if (c == '%')
		return (ft_putchar_fd('%', 1), (1));
	else
		return (ft_putchar_fd(c, 1), (1));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += manage_conversion(format[i], args);
		}
		else
		{
			count += 1;
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
