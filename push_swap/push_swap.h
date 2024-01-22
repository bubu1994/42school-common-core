/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:00:09 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/22 14:50:03 by gebuqaj          ###   ########.fr       */
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
	int				cost;
	int				op_id;
	int				above_m;
	struct t_list	*target;
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
int		get_max(t_list **pile);
int		get_min(t_list **pile);
int		pile_is_sorted(t_list **pile);
void	put_min_at_top(t_list **pile);
void	turk_algo(t_list **a_pile, t_list **b_pile);
void	pushing_to_b(t_list **a_pile, t_list **b_pile);
void	set_medians(t_list **pile);
t_list	*get_max_target(t_list *elem, t_list **pile);
t_list	*get_target(t_list *elem, t_list **b_pile);
void	set_targets(t_list **a_pile, t_list **b_pile);
int		max_of(int a, int b);
void	get_min_cost_and_id(t_list *elem, int c, int id);
void	set_costs_and_id(t_list **a_pile, t_list **b_pile);
void	cost_push(t_list *elem, int a_size, int b_size);
t_list	*elem_to_push(t_list **a_pile, t_list **b_pile);
void	rr_and_ra_or_rb(t_list *elem, t_list **a_pile, t_list **b_pile);
void	rra_and_rb(t_list *elem, t_list **a_pile, t_list **b_pile);
void	ra_and_rrb(t_list *elem, t_list **a_pile, t_list **b_pile);
void	rrr_and_rra_or_rrb(t_list *elem, t_list **a_pile, t_list **b_pile);
void	set_targets_of_b(t_list **a_pile, t_list **b_pile);
t_list	*get_target_of_b(t_list *elem, t_list **a_pile);
t_list	*get_min_target(t_list *elem, t_list **pile);
int		ft_strcmp(const char *s1, const char *s2);
void	print_pile(t_list **pile);
void	print_piles(t_list **a_pile, t_list **b_pile);
void	do_op(char *line, t_list **a_pile, t_list **b_pile);
void	do_op_2(char *line, t_list **a_pile, t_list **b_pile);
void	checker_bonus(t_list **a_pile, t_list **b_pile);
int		main_2(char **argv);

#endif
