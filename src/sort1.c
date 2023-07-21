/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 10:24:01 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/21 13:27:41 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	compare_b(t_stack **b, t_stack **a, int pivot)
{
	t_stack	*current;

	current = *b;
	if (current->content >= pivot)
		pa(b, a);
	else if (current->content < pivot)
		rb(b);
}

static void	sort_b(t_stack **b, t_stack **a, int size)
{
	int		pivot;
	int		i;

	pivot = calculate_median(*b);
	i = 0;
	while (i < size)
	{
		compare_b(b, a, pivot);
		check_a(a);
		i++;
	}
	return ;
}

static void	compare_a(t_stack **a, t_stack **b, int pivot)
{
	t_stack	*current;

	current = *a;
	if (current->content < pivot)
		pb(a, b);
	else
		ra(a);
}

static void	sort_a(t_stack **a, t_stack **b, int size)
{
	int		pivot;
	int		i;

	pivot = calculate_median(*a);
	i = 0;
	while (i < size)
	{
		compare_a(a, b, pivot);
		i++;
	}
	return ;
}

void	sort(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	while (size_a > 3)
	{
		sort_a(a, b, size_a);
		size_a = stack_size(*a);
	}
	sort_three(a);
	size_b = stack_size(*b);
	while (size_b > 0)
	{
		sort_b(b, a, size_b);
		size_b = stack_size(*b);
	}
	return ;
}
