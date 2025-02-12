/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:07:02 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/21 11:46:59 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	manage_integer(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}

int	manage_unsigned(unsigned int num)
{
	char	*str;
	int		len;

	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	str = ft_utoa(num);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}

int	manage_hex_lower(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_hextoa(num, 1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}

int	manage_hex_upper(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_hextoa(num, 0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}
