/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:10:56 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 22:44:40 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *a, int *b, int size_a, int size_b)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	if (size_a < 2 || size_b < 2)
		return ;
	while (i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = temp;
	i = 0;
	temp = b[0];
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = temp;
	ft_printf("rrr\n");
}

int	count_integers(char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (((s[i] >= '0' && s[i] <= '9') || s[i] == ' ')
			|| (s[i] == '-' || s[i] == '+'))
		{
			if (s[i] == 32)
				counter++;
			i++;
		}
		else
			return (-1);
	}
	return (counter);
}

int	parse_integers(char *str, int *a, int counter)
{
	int		j;
	int		i;
	char	*temp;
	int		z;

	z = counter;
	i = 0;
	while (z >= 0)
	{
		j = 0;
		temp = malloc(sizeof(char) * 12);
		if (!temp)
			return (-1);
		while (str[i] != ' ' && str[i] != '\0')
			temp[j++] = str[i++];
		i++;
		temp[j] = '\0';
		if (ft_check_input(temp, a, counter, ((counter + 1) - (z + 1))) == 1)
			return (free(temp), -1);
		a[z] = ft_atoi_ps(temp);
		free(temp);
		z--;
	}
	return (0);
}
