/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:06:48 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 22:44:59 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int size_a)
{
	int	temp;

	if (size_a < 2)
		return ;
	temp = a[size_a - 1];
	a[size_a - 1] = a[size_a - 2];
	a[size_a - 2] = temp;
	ft_printf("sa\n");
}

void	sb(int *b, int size_b)
{
	int	temp;

	if (size_b < 2)
		return ;
	temp = b[size_b - 1];
	b[size_b - 1] = b[size_b - 2];
	b[size_b - 2] = temp;
	ft_printf("sb\n");
}

void	ss(int *a, int *b, int size_a, int size_b)
{
	int	temp;
	int	temp2;

	if (size_a < 2 || size_b < 2)
		return ;
	temp = a[size_a - 1];
	temp2 = b[size_b - 1];
	a[size_a - 1] = a[size_a - 2];
	a[size_a - 2] = temp;
	b[size_b - 1] = b[size_b - 2];
	b[size_b - 2] = temp2;
	ft_printf("ss\n");
}

void	pa(int *a, int *b, int *size_a, int *size_b)
{
	if (*size_b < 1)
		return ;
	a[*size_a] = b[*size_b - 1];
	(*size_a)++;
	(*size_b)--;
	ft_printf("pa\n");
}

void	pb(int *a, int *b, int *size_a, int *size_b)
{
	if (*size_a < 1)
		return ;
	b[*size_b] = a[*size_a - 1];
	(*size_b)++;
	(*size_a)--;
	ft_printf("pb\n");
}
