/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:36:42 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/21 11:41:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

int	manage_char(char c)
{
	if (c >= 0 && c < 127)
		return (ft_putchar_fd(c, 1), (1));
	return (ft_putchar_fd(c, 1), (0));
}

int	manage_string(char *s)
{
	int	len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = 0;
	if (s)
	{
		ft_putstr_fd(s, 1);
		len = ft_strlen(s);
	}
	return (len);
}

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	manage_pointer(unsigned long long ptr)
{
	int	print_length;

	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	print_length = 0;
	print_length += write(1, "0x", 2);
	ft_put_ptr(ptr);
	print_length += ft_ptr_len(ptr);
	return (print_length);
}
