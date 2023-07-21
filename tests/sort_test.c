/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 10:24:01 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/21 13:22:53 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	while (a != NULL && a->next != NULL)
	{
		ft_printf("stack a: [%i]\n", a->content);
		a = a->next;
	}
	if (a != NULL)
		ft_printf("stack a: [%i]\n", a->content);
	while (b != NULL && b->next != NULL)
	{
		ft_printf("stack b: [%i]\n", b->content);
		b = b->next;
	}
	if (b != NULL)
		ft_printf("stack b: [%i]\n", b->content);
}

void	compare_b(t_stack **b, t_stack **a, int pivot)
{
	t_stack	*current;

	current = *b;
	if (current->content > pivot)
		pa(b, a);
	else
		rb(b);
}

void	sort_b(t_stack **b, t_stack **a, int size)
{
	int		pivot;
	int		i;

	pivot = calculate_median(*b);
	ft_printf("pivot: %i\n", pivot);
	i = 0;
	while (i < size)
	{
		compare_b(b, a, pivot);
		i++;
	}
	return ;
}

void	compare_a(t_stack **a, t_stack **b, int pivot)
{
	t_stack	*current;

	current = *a;
	if (current->content <= pivot)
		pb(a, b);
	else
		ra(a);
}

void	sort_a(t_stack **a, t_stack **b, int size)
{
	int		pivot;
	int		i;

	pivot = calculate_median(*a);
	ft_printf("pivot: %i\n", pivot);
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
	while (size_a > 1)
	{
		sort_a(a, b, size_a);
		print_stacks(*a, *b);
		size_a = stack_size(*a);
	}
	size_b = stack_size(*b);
	while (size_b > 1)
	{
		sort_b(b, a, size_b);
		print_stacks(*a, *b);
		size_b = stack_size(*b);
	}
	pa(b, a);
	print_stacks(*a, *b);
	return ;
}
