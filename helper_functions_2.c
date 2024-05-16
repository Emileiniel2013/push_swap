/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:05:16 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/14 22:41:46 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_into_a(int *a, int *b, int size_a, int size_b)
{
	t_moves	best;

	best = get_best_move_ab(a, b, size_a, size_b);
	while (best.ma < 0 && best.mb < 0 && best.ma++ && best.mb++)
		rrr(a, b, size_a, size_b);
	while (best.ma > 0 && best.mb > 0 && best.ma-- && best.mb--)
		rr(a, b, size_a, size_b);
	while (best.ma > 0 && best.ma--)
		ra(a, size_a);
	while (best.mb > 0 && best.mb--)
		rb(b, size_b);
	while (best.ma < 0 && best.ma++)
		rra(a, size_a);
	while (best.mb < 0 && best.mb++)
		rrb(b, size_b);
}

void	sort_into_b(int *a, int *b, int size_a, int size_b)
{
	t_moves	best;

	best = get_best_move_ba(b, a, size_b, size_a);
	while (best.ma < 0 && best.mb < 0 && best.ma++ && best.mb++)
		rrr(a, b, size_a, size_b);
	while (best.ma > 0 && best.mb > 0 && best.ma-- && best.mb--)
		rr(a, b, size_a, size_b);
	while (best.ma > 0 && best.ma--)
		ra(a, size_a);
	while (best.mb > 0 && best.mb--)
		rb(b, size_b);
	while (best.ma < 0 && best.ma++)
		rra(a, size_a);
	while (best.mb < 0 && best.mb++)
		rrb(b, size_b);
}

void	put_into_position(int *a, int size_a)
{
	int	i;

	i = get_remaining_moves(a, size_a);
	if (i < 0)
		rra(a, size_a);
	else if (i > 0)
		ra(a, size_a);
}

int	parse_list(char *str, int **a)
{
	int			i;
	int			counter;

	i = 0;
	counter = count_integers(str);
	if (counter == -1)
		return (-1);
	*a = malloc(sizeof(int) * (counter + 1));
	if (!*a)
		return (-1);
	if (parse_integers(str, *a, counter) == -1)
		return (free(*a), -1);
	return (counter + 1);
}

int	parse_args(int argc, char *argv[], int **a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*a = malloc(sizeof(int) * (argc - 1));
	if (!*a)
		return (-1);
	while (++i < argc)
	{
		if (ft_check_input(argv[i], *a, (argc - 2), j) == 1)
			return (free(*a), -1);
		(*a)[argc - i - 1] = ft_atoi_ps(argv[i]);
		j++;
	}
	i = argc - 1;
	return (i);
}
