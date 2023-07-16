/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 11:53:00 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/16 12:21:51 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	(push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
*/

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*first_node;

	first_node = *b;
	*b = first_node->next;
	if (first_node == NULL)
		return ;
	stack_add_front(a, first_node);
	ft_printf("pa\n");
}

/*	(push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*first_node;

	first_node = *a;
	*a = first_node->next;
	if (first_node == NULL)
		return ;
	stack_add_front(b, first_node);
	ft_printf("pb\n");
}
