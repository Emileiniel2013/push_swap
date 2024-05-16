/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_brain_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:28:49 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 20:08:37 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_opt_ba(int targ, int *arr, int arr_size)
{
	int	i;
	int	best_index;
	int	closest_highest;

	i = arr_size - 1;
	best_index = -1;
	closest_highest = INT_MAX;
	while (i >= 0)
	{
		if (arr[i] > targ && arr[i] < closest_highest)
		{
			closest_highest = arr[i];
			best_index = i;
		}
		i--;
	}
	return (best_index);
}

int	get_best_mv_ba_2(int targ, int *src, int arr_size, t_range maxmin)
{
	int	i;
	int	best_move;

	i = arr_size - 1;
	best_move = 0;
	if (targ > maxmin.min && targ < maxmin.max)
	{
		i = find_best_opt_ba(targ, src, arr_size);
		if (i < arr_size / 2)
			best_move = 0 - (i + 1);
		else
			best_move = arr_size - (i + 1);
	}
	else if (targ > maxmin.max || targ < maxmin.min)
	{
		while (src[i] != maxmin.min)
			i--;
		if (i < arr_size / 2)
			best_move = 0 - (i + 1);
		else
			best_move = arr_size - (i + 1);
	}
	return (best_move);
}

t_moves	get_best_move_ba(int *b, int *a, int size_b, int size_a)
{
	int		i;
	t_moves	best_move;
	t_moves	temp;
	t_range	minmax;

	i = size_b - 1;
	best_move.total = INT_MAX;
	while (i >= 0)
	{
		minmax = define_min_max(a, size_a);
		if (i < size_b / 2)
			temp.mb = 0 - (i + 1);
		else
			temp.mb = size_b - (i + 1);
		temp.ma = get_best_mv_ba_2(b[i], a, size_a, minmax);
		temp.total = calc_total(temp.ma, temp.mb);
		if (temp.total < best_move.total)
			apply_values(&best_move, temp.ma, temp.mb, temp.total);
		if (best_move.total == 0)
			return (best_move);
		i--;
	}
	return (best_move);
}

int	get_remaining_moves(int *a, int size_a)
{
	t_range	minmax;
	int		j;
	int		y;

	j = 0;
	minmax = define_min_max(a, size_a);
	while (a[j] != minmax.min)
		j++;
	if (j < size_a / 2)
		y = 0 - (j + 1);
	else
		y = size_a - (j + 1);
	return (y);
}

void	apply_values(t_moves *best_move, int atmp, int btmp, int totaltmp)
{
	best_move->ma = atmp;
	best_move->mb = btmp;
	best_move->total = totaltmp;
}
