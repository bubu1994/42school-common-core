/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:11:03 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/10/24 15:07:21 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}
/*
#include <strings.h>
int	main()
{
	char c[] = "hola";
	printf("%s:\n", bzero(c, 2));

	return (0);
}*/
