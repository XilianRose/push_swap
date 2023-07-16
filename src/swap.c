/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 14:49:36 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/16 12:20:49 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	Swap the first 2 elements at the top of stack a. Do nothing if there is only
	one or no elements.
*/
void	sa(t_stack **a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	first_node = *a;
	second_node = first_node->next;
	third_node = second_node->next;
	if (first_node == NULL || second_node == NULL)
		return ;
	*a = second_node;
	second_node->next = first_node;
	first_node->next = third_node;
	ft_printf("sa\n");
}

/*	Swap the first 2 elements at the top of stack b. Do nothing if there is only
	one or no elements.
*/
void	sa(t_stack **b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	first_node = *b;
	second_node = first_node->next;
	third_node = second_node->next;
	if (first_node == NULL || second_node == NULL)
		return ;
	*b = second_node;
	second_node->next = first_node;
	first_node->next = third_node;
	ft_printf("sb\n");
}

/*	sa and sb at the same time.
*/
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
