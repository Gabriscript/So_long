/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:03:51 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/06 12:04:01 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static unsigned int	int_count(long n);

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*string;
	long			num;

	num = n;
	len = int_count(num);
	string = malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[len] = '\0';
	if (num == 0)
		string[0] = '0';
	if (num < 0)
	{
		string[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		len--;
		string[len] = (num % 10) + '0';
		num /= 10;
	}
	return (string);
}

static unsigned int	int_count(long n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
