/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:49:43 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 22:44:29 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Utils/libft/libft.h"
# include <limits.h>

typedef struct s_moves
{
	int	ma;
	int	mb;
	int	total;
}		t_moves;

typedef struct s_range
{
	int	min;
	int	max;
}		t_range;

void		ft_push_swap(int *a, int *b, int size);
int			ft_check_int(char *input);
long long	ft_atoi_ps(const char *str);
int			parse_list(char *str, int **a);
int			ft_check_input(char *input, int *a, int size, int j);
void		sa(int *a, int size_a);
void		sb(int *b, int size_b);
void		ss(int *a, int *b, int size_a, int size_b);
void		pa(int *a, int *b, int *size_a, int *size_b);
void		pb(int *a, int *b, int *size_a, int *size_b);
void		ra(int *a, int size_a);
void		rb(int *b, int size_b);
void		rr(int *a, int *b, int size_a, int size_b);
void		rra(int *a, int size_a);
void		rrb(int *b, int size_b);
void		rrr(int *a, int *b, int size_a, int size_b);
void		simple_swap(int *a, int size_a);
int			check_if_sorted(int *a, int size_a);
t_moves		get_best_move_ab(int *a, int *b, int size_a, int size_b);
int			get_best_mv_ab_2(int targ, int *src, int arr_size, t_range maxmin);
t_range		define_min_max(int *arr, int arr_size);
int			find_best_opt_ab(int targ, int *arr, int arr_size);
int			calc_total(int ma, int mb);
t_moves		get_best_move_ba(int *b, int *a, int size_b, int size_a);
int			get_best_mv_ba_2(int targ, int *src, int arr_size, t_range maxmin);
int			find_best_opt_ba(int targ, int *arr, int arr_size);
int			get_remaining_moves(int *a, int size_b);
void		apply_values(t_moves *best_move, int atmp, int btmp, int totaltmp);
void		sort_into_a(int *a, int *b, int size_a, int size_b);
void		sort_into_b(int *a, int *b, int size_a, int size_b);
void		put_into_position(int *a, int size_a);
int			parse_args(int argc, char *argv[], int **a);
int			count_integers(char *str);
int			parse_integers(char *str, int *a, int counter);

#endif