/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:22 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/12 09:33:22 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= 'a' && a <= 'z')
		|| (a >= 'A' && a <= 'Z')
		|| (a >= '0' && a <= '9'))
	{
		return (1);
	}
	return (0);
}
