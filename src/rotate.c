/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 15:06:15 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/14 15:22:42 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	(rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	ra(t_stack **a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	first_node = *a;
	second_node = first_node->next;
	last_node = stack_last(*a);
	*a = second_node;
	last_node->next = first_node;
	first_node->next = NULL;
	ft_printf("ra\n");
}

/*	(rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/

/*	ra and rb at the same time.
*/
