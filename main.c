/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:15:46 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/16 13:35:58 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		i = parse_list(argv[1], &a);
		if (i == -1)
			return (write(2, "Error\n", 6), 1);
	}
	else
	{
		i = parse_args(argc, argv, &a);
		if (i == -1)
			return (write(2, "Error\n", 6), 1);
	}
	if (check_if_sorted(a, i) == 0)
		return (free(a), 0);
	b = malloc(sizeof(int) * i);
	if (!b)
		return (free(a), write(2, "Error\n", 6), 1);
	ft_push_swap(a, b, i);
	return (free(a), free(b), 0);
}
