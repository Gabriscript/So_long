/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggrgani@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:44:48 by ggargani          #+#    #+#             */
/*   Updated: 2024/10/31 10:45:54 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
		{
			return (string1[i] - string2[i]);
		}
		i++;
	}
	return (0);
}
