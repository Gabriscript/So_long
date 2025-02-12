/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:17:09 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/06 11:30:42 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	const unsigned char	*src;
	size_t				i;
	unsigned char		*dest;

	i = 0;
	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
