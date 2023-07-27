/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort-small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 10:24:01 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/27 11:49:33 by mstegema      ########   odam.nl         */
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

void	sort_three(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = first->next;
	if (second == NULL)
		return ;
	third = second->next;
	if (stack_size(*a) == 3)
	{
		if (first->content > third->content
			&& first->content > second->content)
			ra(a);
		else if (second->content > third->content
			&& second->content > first->content)
			rra(a);
	}
	first = *a;
	second = first->next;
	if (first->content > second->content)
		sa(a);
}

// void	sort_three(t_stack **a)
// {
// 	t_stack	*first;
// 	t_stack	*second;
// 	t_stack	*third;

// 	first = *a;
// 	second = first->next;
// 	third = second->next;
// 	if (stack_size(*a) == 3)
// 	{
// 		if (first->content > third->content
// 			&& first->content > second->content)
// 		{
// 			ra(a);
// 			if (second->content > third->content)
// 				sa(a);
// 		}
// 		else if (second->content > third->content
// 			&& second->content > first->content)
// 		{
// 			rra(a);
// 			if (third->content > first->content)
// 				sa(a);
// 		}
// 	}
// 	if (first->content > second->content)
// 		sa(a);
// }

static void	phase_one(t_stack **a, t_stack **b, int size, int pivot)
{
	int		current_size;
	int		i;
	int		node_index;

	i = 0;
	current_size = size;
	while (i < size)
	{
		node_index = find_node(a, pivot);
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

