/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_brain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:15:59 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 20:07:38 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_total(int ma, int mb)
{
	int	moves_a;
	int	moves_b;
	int	total;

	total = 0;
	moves_a = ma;
	moves_b = mb;
	while (moves_a < 0 && moves_b < 0)
	{
		total++;
		moves_a++;
		moves_b++;
	}
	while (moves_a > 0 && moves_b > 0)
	{
		total++;
		moves_a--;
		moves_b--;
	}
	if (moves_a < 0)
		moves_a = moves_a * -1;
	if (moves_b < 0)
		moves_b = moves_b * -1;
	total += moves_a + moves_b;
	return (total);
}

int	find_best_opt_ab(int targ, int *arr, int arr_size)
{
	int	i;
	int	best_index;
	int	closest_lowest;

	i = arr_size - 1;
	best_index = -1;
	closest_lowest = INT_MIN;
	while (i >= 0)
	{
		if (arr[i] < targ && arr[i] > closest_lowest)
		{
			closest_lowest = arr[i];
			best_index = i;
		}
		i--;
	}
	return (best_index);
}

t_range	define_min_max(int *arr, int arr_size)
{
	int		i;
	t_range	minmax;

	i = arr_size - 1;
	minmax.max = INT_MIN;
	minmax.min = INT_MAX;
	while (i >= 0)
	{
		if (arr[i] > minmax.max)
			minmax.max = arr[i];
		if (arr[i] < minmax.min)
			minmax.min = arr[i];
		i--;
	}
	return (minmax);
}

int	get_best_mv_ab_2(int targ, int *src, int arr_size, t_range maxmin)
{
	int	i;
	int	best_move;

	i = arr_size - 1;
	best_move = 0;
	if (targ > maxmin.max || targ < maxmin.min)
	{
		while (src[i] != maxmin.max)
			i--;
		if (i < arr_size / 2)
			best_move = 0 - (i + 1);
		else
			best_move = arr_size - (i + 1);
	}
	else if (targ > maxmin.min && targ < maxmin.max)
	{
		i = find_best_opt_ab(targ, src, arr_size);
		if (i < arr_size / 2)
			best_move = 0 - (i + 1);
		else
			best_move = arr_size - (i + 1);
	}
	return (best_move);
}

t_moves	get_best_move_ab(int *a, int *b, int size_a, int size_b)
{
	int		i;
	t_moves	best_move;
	t_moves	temp;
	t_range	minmax;

	i = size_a - 1;
	best_move.total = INT_MAX;
	while (i >= 0)
	{
		minmax = define_min_max(b, size_b);
		if (i < size_a / 2)
			temp.ma = 0 - (i + 1);
		else
			temp.ma = size_a - (i + 1);
		temp.mb = get_best_mv_ab_2(a[i], b, size_b, minmax);
		temp.total = calc_total(temp.ma, temp.mb);
		if (temp.total < best_move.total)
			apply_values(&best_move, temp.ma, temp.mb, temp.total);
		if (best_move.total == 0)
			return (best_move);
		i--;
	}
	return (best_move);
}
