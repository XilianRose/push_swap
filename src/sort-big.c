/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort-big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 10:40:48 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/24 12:40:54 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	phase_two(t_stack **a, t_stack **b, int size)
{
	int		current_size;
	int		i;
	int		node_index;

	i = 0;
	current_size = size;
	while (i < size)
	{
		current_size = stack_size(*b);
		node_index = phase_two_find_node(b, current_size);
		phase_two_push(a, b, node_index);
		i++;
	}
	return ;
}

static void	phase_one(t_stack **a, t_stack **b, t_pivots *pivots)
{
	int		size;
	int		i;
	int		node_index;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		node_index = find_node_between(a, pivots, pivots->r1, pivots->r2);
		if (node_index != -1)
		{
			phase_one_push(a, b, node_index);
			if (pivots->rb == true)
				rb(b);
		}
		i++;
	}
	return ;
}

void	sort_100(t_stack **a, t_stack **b, t_pivots *pivots)
{
	int			size_b;

	calculate_3_pivots(*a, pivots);
	pivots->r1 = 1;
	pivots->r2 = 2;
	phase_one(a, b, pivots);
	pivots->r1 = 0;
	pivots->r2 = 3;
	phase_one(a, b, pivots);
	size_b = stack_size(*b);
	while (size_b > 0)
	{
		phase_two(a, b, size_b);
		size_b = stack_size(*b);
	}
	return ;
}

void	sort_500(t_stack **a, t_stack **b, t_pivots *pivots)
{
	int			size_b;

	calculate_7_pivots(*a, pivots);
	pivots->r1 = 3;
	pivots->r2 = 4;
	phase_one(a, b, pivots);
	pivots->r1 = 2;
	pivots->r2 = 5;
	phase_one(a, b, pivots);
	pivots->r1 = 1;
	pivots->r2 = 6;
	phase_one(a, b, pivots);
	pivots->r1 = 0;
	pivots->r2 = 7;
	phase_one(a, b, pivots);
	size_b = stack_size(*b);
	while (size_b > 0)
	{
		phase_two(a, b, size_b);
		size_b = stack_size(*b);
	}
	return ;
}
