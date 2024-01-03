/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:57:01 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 18:57:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	print_format(char format, va_list args);
int	print_char(int c);
int	print_str(char *str);
int	print_u(unsigned int n);
int	print_numbase(char format, long n, int base);
int	print_ptr(unsigned long long n);

#endif