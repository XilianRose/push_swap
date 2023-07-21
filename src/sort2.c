/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 10:40:48 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/21 13:31:20 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_a(t_stack **a)
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
