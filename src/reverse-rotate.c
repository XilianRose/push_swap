/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse-rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 12:19:32 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/16 12:57:09 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	(reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rra(t_stack **a)
{
	t_stack	*last_node;
	t_stack	*prev_node;
	int		i;
	int		size;

	i = 0;
	size = stack_size(*a);
	if (size < 2)
		return;
	prev_node = *a;
	while (i < size - 2)
	{
		prev_node = prev_node->next;
		i++;
	}
	last_node = stack_last(*a);
	stack_add_front(a, last_node);
	prev_node->next = NULL;
	ft_printf("rra\n");
}

/*	(reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
*/
void	rrb(t_stack **b)
{
	t_stack	*last_node;
	t_stack	*prev_node;
	int		i;
	int		size;

	i = 0;
	size = stack_size(*b);
	if (size < 2)
		return;
	prev_node = *b;
	while (i < size - 2)
	{
		prev_node = prev_node->next;
		i++;
	}
	last_node = stack_last(*b);
	stack_add_front(b, last_node);
	prev_node->next = NULL;
	ft_printf("rrb\n");
}

/*	rrr : rra and rrb at the same time.
*/
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
