/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:00:09 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:20:27 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_list
{
	int				nb;
	int				pos;
	struct t_list	*next;
}	t_list;

long	ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
int		sizetab(const char *s, char c);
char	**ft_split_m(char const *s, char c);
t_list	*create_pile(char **argv);
void	free_liste(t_list *liste);
void	free_ar(char **ar, int size);
int		check_args(char **argv);
void	swap(t_list *pile);
void	swap_a(t_list *a_pile);
void	swap_b(t_list *b_pile);
void	swap_ss(t_list *a_pile, t_list *b_pile);
void	push(t_list	**src, t_list **dest);
void	push_a(t_list **src, t_list **dest);
void	push_b(t_list **src, t_list **dest);
void	rotate(t_list **pile);
void	rotate_a(t_list **pile);
void	rotate_b(t_list **pile);
void	rotate_ab(t_list **a_pile, t_list **b_pile);
void	rrotate(t_list **pile);
void	rrotate_a(t_list **pile);
void	rrotate_b(t_list **pile);
void	rrotate_ab(t_list **a_pile, t_list **b_pile);
void	tri_2(t_list **a_pile);
void	tri_3(t_list **a_pile);
void	trier(t_list **a_pile, t_list **b_pile, int size);
int		get_max(t_list **pile);
int		get_min(t_list **pile);
int		pile_is_sorted(t_list **pile);
void	put_min_at_top(t_list **pile);

#endif
