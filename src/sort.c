/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 10:24:01 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/20 12:58:56 by mstegema      ########   odam.nl         */
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

int	sort_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*next;
	int		pivot;

	current = *a;
	next = NULL;
	pivot = calculate_median(*a);
	ft_printf("pivot: %i\n", pivot);
	while (current->next != NULL)
	{
		next = current->next;
		if (current->content > pivot)
			pb(a, b);
		else
			ra(a);
		current = next;
	}
	return (0);
}

int	sort(t_stack **head_a, t_stack **head_b)
{
	int	size;

	size = 2;
	while (size > 1)
	{
		sort_a(head_a, head_b);
		print_stacks(*head_a, *head_b);
		size = stack_size(*head_a);
	}
	return (0);
}

