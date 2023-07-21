/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 10:24:01 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/21 16:17:24 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_a(t_stack **a)
{
	t_stack	*head_a;


	head_a = *a;
	if (head_a->content > head_a->next->content)
	{
		sa(a);
		if ((head_a->content > head_a->next->content))
		{
			ra(a);
			check_a(a);
			rra(a);
		}
	}
}

static void	compare_b(t_stack **b, t_stack **a, int pivot)
{
	t_stack	*current;

	current = *b;
	if (current->content >= pivot)
		pa(b, a);
	else if (current->content < pivot)
		rb(b);
}

void	sort_b(t_stack **b, t_stack **a, int size, int pivot)
{
	int		i;

	i = 0;
	while (i < size)
	{
		compare_b(b, a, pivot);
		check_a(a);
		i++;
	}
	return ;
}

static void	compare_a(t_stack **a, t_stack **b, int *pivots)
{
	t_stack	*current;

	current = *a;
	if (current->content < pivots[0])
	{
		pb(a, b);
		if (current->content < pivots[1])
			rb(b);
	}
	else
		ra(a);
}

// static void	compare_a(t_stack **a, t_stack **b, int pivot)
// {
// 	t_stack	*current;

// 	current = *a;
// 	if (current->content < pivot)
// 		pb(a, b);
// 	else
// 		ra(a);
// }

void	sort_a(t_stack **a, t_stack **b, int size, int *pivots)
{
	int		i;

	i = 0;
	while (i < size)
	{
		compare_a(a, b, pivots);
		i++;
	}
	return ;
}

// void	sort_a(t_stack **a, t_stack **b, int size, int pivot)
// {
// 	int		i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		compare_a(a, b, pivot);
// 		i++;
// 	}
// 	return ;
// }

