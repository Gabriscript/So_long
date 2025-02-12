/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:33:00 by ggargani          #+#    #+#             */
/*   Updated: 2024/10/31 17:01:51 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else
	{
		total_size = nmemb * size;
		if (total_size / nmemb != size)
			return (NULL);
	}
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
