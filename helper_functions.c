/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:32:54 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 13:35:13 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_ps(const char *str)
{
	int			posorneg;
	long long	number;

	number = 0;
	posorneg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			posorneg = posorneg * -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	return (number * posorneg);
}

int	ft_check_int(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		input++;
	if (input[i] == '\0')
		return (1);
	while (input[i] != '\0')
	{
		if (*input < '0' || *input > '9')
			return (1);
		else
			input++;
	}
	return (0);
}

int	ft_check_input(char *input, int *a, int size, int j)
{
	long long	num;
	int			i;

	if (ft_check_int(input) == 1)
		return (1);
	num = ft_atoi_ps(input);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	i = size;
	while (j > 0)
	{
		if (num == a[i])
			return (1);
		i--;
		j--;
	}
	return (0);
}

void	simple_swap(int *a, int size_a)
{
	while (check_if_sorted(a, size_a) == 1)
	{
		if (a[2] < a[1] && a[1] > a[0])
		{
			sa(a, size_a);
			ra(a, size_a);
		}
		else if (a[2] > a[1] && a[0] < a[2])
		{
			ra(a, size_a);
			sa(a, size_a);
		}
		else if (a[2] > a[1])
			sa(a, size_a);
		else if (a[0] < a[2])
			ra(a, size_a);
	}
}

int	check_if_sorted(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}
