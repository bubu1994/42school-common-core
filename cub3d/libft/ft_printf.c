/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:51:05 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 18:51:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += print_numbase(format, (long) va_arg(args, int), 10);
	else if (format == 'u')
		count += print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += print_numbase(format, (long) va_arg(args, unsigned int), 16);
	else if (format == 'p')
	{
		count += write(1, "0x", 2);
		count += print_ptr((unsigned long long) va_arg(args, uintptr_t));
	}
	else
		count += write(1, &format, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += print_format(str[i++ + 1], args);
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <limits.h>
#include <inttypes.h>

int	main(void)
{
	int t = printf("bonjour %c, %s, %d, %x, %X\n", 
	'G', "hola", -4511, -4511, 4511);
	printf("");
	int t2 = ft_printf("BONJOUR %c, %s, %d, %x, %X\n", 
	'G', "hola", -4511, -4511, 4511);
	printf("%d, %d\n\n", t, t2);

	printf("%s\n", (char *)NULL);
	ft_printf("%s\n\n", (char *)NULL);

	printf("%x, %x\n", -4511, UINT_MAX - 4510);

	printf("taille max uintptr_t = 
	plage d'adresses que le pointeur peut couvrir: %" PRIuPTR "\n", UINTPTR_MAX);
	printf("max ulong:%lu, maxu ulong long:%llu\n", ULONG_MAX, ULLONG_MAX);
	printf("%p\n", (void *)-14523);
	ft_printf("%p\n", (void *)-14523);
	return (0);
}
*/
/*On declare une varibale de type va_list, cette variable va contenir tous
les arguments en commencant (va_start) par le dernier connu (qui est str).
A chaque appel de va_arg, va_arg prend l'argument suivant dans
la liste/variable 'args'. (Donc la 1ere fois qu'on appelle va_arg, il prend
ce qui suit l'argument 'str')

"En général, lorsqu'un entier signé est converti en un entier non signé de 
taille équivalente, le résultat est le reste après la division du nombre signé 
par le nombre qui représente la plage de valeurs non signées."
unsigned int = -1 = UINT_MAX - 1 = 4294967295
*/