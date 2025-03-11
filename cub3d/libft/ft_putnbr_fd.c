/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:03:47 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/10/31 17:16:20 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb <= 9 && nb >= 0)
	{
		ft_putchar_fd(nb + 48, fd);
	}
}
/*
int	main(void)
{
	int	n = 14;
	int fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
}*/
