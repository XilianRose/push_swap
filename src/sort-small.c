/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort-small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 10:24:01 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/23 16:02:24 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	phase_two_find_node(t_stack **b, int size)
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

static int	find_node(t_stack **a, int size, int pivot)
{
	t_stack	*current;
	int		i;

	current = *a;
	i = 0;
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

void	phase_two(t_stack **a, t_stack **b, int size)
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

void	phase_one(t_stack **a, t_stack **b, int size, int pivot)
{
	int		current_size;
	int		i;
	int		node_index;

	i = 0;
	current_size = size;
	while (i < size)
	{
		current_size = stack_size(*a);
		node_index = find_node(a, current_size, pivot);
		if (node_index != -1)
			phase_one_push(a, b, node_index);
		i++;
	}
	return ;
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size_a;
	int	pivot;
	int	size_b;

	size_a = stack_size(*a);
	while (size_a > 3)
	{
		pivot = calculate_median(*a);
		phase_one(a, b, size_a, pivot);
		size_a = stack_size(*a);
	}
	sort_three(a);
	size_b = stack_size(*b);
	while (size_b > 0)
	{
		pivot = calculate_median(*b);
		phase_two(a, b, size_b);
		size_b = stack_size(*b);
	}
	return ;
}

