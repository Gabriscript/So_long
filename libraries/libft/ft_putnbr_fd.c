/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:28:06 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/05 10:52:21 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <limits.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		num = (n % 10) + '0';
		write(fd, &num, 1);
	}
	else
	{
		num = n + '0';
		write(fd, &num, 1);
	}
}
