/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcsdiuxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:49:40 by marvin            #+#    #+#             */
/*   Updated: 2023/11/14 20:49:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	print_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		return (print_char(n + '0'));
	else
	{
		count = print_u(n / 10);
		return (count + print_u(n % 10));
	}
}

int	print_numbase(char format, long n, int base)
{
	int		count;
	char	*chiffres;

	count = 0;
	if (format == 'X')
		chiffres = "0123456789ABCDEF";
	else
		chiffres = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_numbase(format, -n, base) + 1);
	}
	else if (n < base)
		return (print_char(chiffres[n]));
	else
	{
		count = print_numbase(format, n / base, base);
		return (count + print_numbase(format, n % base, base));
	}
}

int	print_ptr(unsigned long long n)
{
	int		count;
	char	*chiffres;

	count = 0;
	chiffres = "0123456789abcdef";
	if (n < 16)
		return (print_char(chiffres[n]));
	else
	{
		count = print_ptr(n / 16);
		return (count + print_ptr(n % 16));
	}
}
/*
int	print_d(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		write(1, "-", 1);
		return (print_num(-n) + 1);
	}
	else if (n < 10)
	{
		return print_char(n + '0');
	}
	else
		count = print_num(n / 10);
		return (count + print_num(n % 10));
}*/