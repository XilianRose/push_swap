/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort-utils                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/23 15:56:58 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/23 16:01:42 by mstegema      ########   odam.nl         */
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

void	sort_three(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (first->content > third->content
		&& first->content > second->content)
	{
		ra(a);
		if (second->content > third->content)
			sa(a);
	}
	else if (second->content > third->content
		&& second->content > first->content)
	{
		rra(a);
		if (third->content > first->content)
			sa(a);
	}
	else if (first->content > second->content)
		sa(a);
}
