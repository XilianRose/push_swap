/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort-utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/23 15:56:58 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/24 12:15:46 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	phase_two_push(t_stack **a, t_stack **b, int node_index)
{
	t_stack	*node;

	node = *b;
	while (node_index != 0)
	{
		node = node->next;
		node_index--;
	}
	if (node->cost.r <= node->cost.rr)
	{
		while (node->cost.r != 0)
		{
			rb(b);
			node->cost.r--;
		}
	}
	else if (node->cost.r > node->cost.rr)
	{
		while (node->cost.rr != 0)
		{
			rrb(b);
			node->cost.rr--;
		}
	}
	pa(b, a);
}

void	phase_one_push(t_stack **a, t_stack **b, int node_index)
{
	t_stack	*node;

	node = *a;
	while (node_index != 0)
	{
		node = node->next;
		node_index--;
	}
	if (node->cost.r <= node->cost.rr)
	{
		while (node->cost.r != 0)
		{
			ra(a);
			node->cost.r--;
		}
	}
	else if (node->cost.r > node->cost.rr)
	{
		while (node->cost.rr != 0)
		{
			rra(a);
			node->cost.rr--;
		}
	}
	pb(a, b);
}

int	phase_two_find_node(t_stack **b, int size)
{
	t_stack	*current;
	int		i;
	int		res;
	int		highest;

	current = *b;
	i = 0;
	res = i;
	highest = current->content;
	current->cost.r = i;
	current->cost.rr = size - i;
	while (i < size)
	{
		if (highest < current->content)
		{
			highest = current->content;
			current->cost.r = i;
			current->cost.rr = size - i;
			res = i;
		}
		i++;
		current = current->next;
	}
	return (res);
}

int	find_node_between(t_stack **a, t_pivots *pivots, int r1, int r2)
{
	t_stack	*current;
	int		i;

	current = *a;
	i = 0;
	while (i < stack_size(*a))
	{
		if ((current->content >= pivots->pivot[r1]
				&& current->content <= pivots->pivot[r1 + 1])
			|| (current->content >= pivots->pivot[r2]
				&& current->content <= pivots->pivot[r2 + 1]))
		{
			current->cost.r = i;
			current->cost.rr = stack_size(*a) - i;
			pivots->rb = false;
			if (current->content >= pivots->pivot[r1]
				&& current->content <= pivots->pivot[r1 + 1])
				pivots->rb = true;
			return (i);
		}
		i++;
		current = current->next;
	}
	return (-1);
}

int	find_node(t_stack **a, int pivot)
{
	t_stack	*current;
	int		size;
	int		i;

	current = *a;
	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if (current->content < pivot)
		{
			current->cost.r = i;
			current->cost.rr = size - i;
			return (i);
		}
		i++;
		current = current->next;
	}
	return (-1);
}
