/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:28:33 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 22:44:48 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *a, int size_a)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	if (size_a < 2)
		return ;
	while (i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = temp;
	ft_printf("rra\n");
}

void	rrb(int *b, int size_b)
{
	int	temp;
	int	i;

	i = 0;
	temp = b[0];
	if (size_b < 2)
		return ;
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = temp;
	ft_printf("rrb\n");
}

void	rr(int *a, int *b, int size_a, int size_b)
{
	int	temp;
	int	i;

	i = size_a - 1;
	temp = a[size_a - 1];
	if (size_a < 2 || size_b < 2)
		return ;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	i = size_b - 1;
	temp = b[size_b - 1];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	ft_printf("rr\n");
}

void	ra(int *a, int size_a)
{
	int	temp;
	int	i;

	i = size_a - 1;
	temp = a[size_a - 1];
	if (size_a < 2)
		return ;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	ft_printf("ra\n");
}

void	rb(int *b, int size_b)
{
	int	temp;
	int	i;

	i = size_b - 1;
	temp = b[size_b - 1];
	if (size_b < 2)
		return ;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	ft_printf("rb\n");
}
