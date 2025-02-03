/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:24:00 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/05 10:50:51 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdlib.h>

char	*ft_strtrim(char const *s, char const *c)
{
	size_t	start;
	size_t	end;
	char	*str;
	size_t	i;

	if (!s || !c)
		return (NULL);
	if (!*s)
		return (ft_calloc(1, sizeof(char)));
	start = 0;
	while (s[start] && ft_strchr(c, s[start]))
		start++;
	end = ft_strlen(s);
	while (end > start && ft_strchr(c, s[end - 1]))
		end--;
	if (start >= end)
		return (ft_calloc(1, sizeof(char)));
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
