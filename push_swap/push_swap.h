/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:00:09 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/03 13:34:59 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct Nombre_l
{
	int	nb;
	int	pos;
	struct Nombre_l	*next;
} Nombre_l;

int	ft_atoi(const char *str);
int	ft_lstsize(Nombre_l *lst);
Nombre_l	*ft_lstlast(Nombre_l *lst);

void	swap(Nombre_l *pile);
void	swap_a(Nombre_l *a_pile);
void	swap_b(Nombre_l *b_pile);
void	swap_ss(Nombre_l *a_pile, Nombre_l *b_pile);

void	push(Nombre_l	**src, Nombre_l **dest);
void	push_a(Nombre_l **src, Nombre_l **dest);
void	push_b(Nombre_l **src, Nombre_l **dest);

void	rotate(Nombre_l **pile);
void	rotate_a(Nombre_l **pile);
void	rotate_b(Nombre_l **pile);
void	rotate_ab(Nombre_l **a_pile, Nombre_l **b_pile);

void	rrotate(Nombre_l **pile);
void	rrotate_a(Nombre_l **pile);
void	rrotate_b(Nombre_l **pile);
void	rrotate_ab(Nombre_l **a_pile, Nombre_l **b_pile);

void	tri_2(Nombre_l **a_pile);


#endif