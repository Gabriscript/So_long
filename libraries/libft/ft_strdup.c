/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:33:26 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/01 09:08:34 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	char	*temp;

	len = ft_strlen(s);
	dup = malloc((len + 1) * sizeof(char));
	temp = dup;
	if (dup == NULL)
		return (NULL);
	while (*s)
	{
		*temp = *s;
		temp++;
		s++;
	}
	*temp = '\0';
	return (dup);
}
