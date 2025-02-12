/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:48:35 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/21 11:58:24 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

int		manage_pointer(unsigned long long ptr);
int		manage_conversion(char c, va_list args);
int		ft_printf(const char *format, ...);
int		manage_string(char *s);
int		manage_char(char c);
int		manage_integer(int num);
int		manage_unsigned(unsigned int num);
int		manage_hex_lower(unsigned int num);
int		manage_hex_upper(unsigned int num);
char	*ft_utoa(unsigned long long n);
char	*ft_hextoa(unsigned long long num, int lowercase);

#endif
