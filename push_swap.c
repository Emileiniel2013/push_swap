/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:49:22 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 20:04:35 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(int *a, int *b, int size)
{
	int		size_a;
	int		size_b;

	size_a = size;
	size_b = 0;
	if (size == 3)
		return (simple_swap(a, size_a));
	while (size_b != 2 && size_a > 3)
		pb(a, b, &size_a, &size_b);
	while (size_a > 3)
	{
		sort_into_a(a, b, size_a, size_b);
		pb(a, b, &size_a, &size_b);
	}
	simple_swap(a, size_a);
	while (size_b > 0)
	{
		sort_into_b(a, b, size_a, size_b);
		pa(a, b, &size_a, &size_b);
	}
	while (check_if_sorted(a, size_a) != 0)
		put_into_position(a, size_a);
}
