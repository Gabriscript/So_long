/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:27:34 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/01 10:51:56 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*subs;
	size_t		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
	{
		subs = ft_calloc(1, sizeof(char));
		if (!subs)
			return (NULL);
		return (subs);
	}
	if (start + len > size)
		len = size - start;
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	subs[len] = '\0';
	while (len--)
		subs[len] = s[start + len];
	return (subs);
}
