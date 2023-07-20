/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 10:24:01 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/20 15:16:29 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	compare_b(t_stack **b, t_stack **a, int pivot)
{
	t_stack	*current;

	current = *b;
	if (current->content <= pivot)
		pa(b, a);
	else
		rb(b);
}

int	sort_b(t_stack **b, t_stack **a, int size)
{
	int		pivot;
	int		i;

	pivot = calculate_median(*b);
	i = 0;
	while (i < size)
	{
		compare_b(b, a, pivot);
		i++;
	}
	return (0);
}

void	compare_a(t_stack **a, t_stack **b, int pivot)
{
	t_stack	*current;

	current = *a;
	if (current->content > pivot)
		pb(a, b);
	else
		ra(a);
}

int	sort_a(t_stack **a, t_stack **b, int size)
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
	return (0);
}

int	sort(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	while (size_a > 1)
	{
		sort_a(a, b, size_a);
		size_a = stack_size(*a);
	}
	size_b = stack_size(*b);
	while (size_b > 1)
	{
		sort_b(b, a, size_b);
		size_b = stack_size(*b);
	}
	pa(b, a);
	return (0);
}
