/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:34:54 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/06 12:06:30 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<limits.h>

static int	oflow(int sign);

int	ft_atoi(const char *s)
{
	unsigned long long	result;
	int					sign;

	sign = 1;
	result = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if ((result > LLONG_MAX / 10)
			|| (result == LLONG_MAX / 10 && *s - '0' > LLONG_MAX % 10))
			return (oflow(sign));
		result = result * 10 + (*s - '0');
		s++;
	}
	return ((int)sign * result);
}

static int	oflow(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}
