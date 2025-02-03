/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xxtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:03:51 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/21 11:53:16 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdlib.h>
#define HEXL "0123456789abcdef"
#define HEXU "0123456789ABCDEF"

static unsigned int	int_count(long long n)
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

static char	*l_or_u(int i)
{
	if (i == 1)
		return (HEXL);
	else
		return (HEXU);
}

char	*ft_utoa(unsigned long long n)
{
	char				*string;
	unsigned long long	num;
	unsigned int		len;

	num = (unsigned long long)n;
	len = int_count(num);
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[len] = '\0';
	if (num == 0)
		string[0] = '0';
	while (num > 0)
	{
		len--;
		string[len] = (num % 10) + '0';
		num /= 10;
	}
	return (string);
}

char	*ft_hextoa(unsigned long long num, int lowercase)
{
	char				*hex_digits;
	char				*str;
	unsigned long long	len;
	unsigned long long	temp;

	temp = num;
	len = 1;
	hex_digits = l_or_u(lowercase);
	while (temp / 16 > 0)
	{
		temp /= 16;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = hex_digits[num % 16];
		num /= 16;
	}
	return (str);
}
