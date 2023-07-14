/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 14:46:40 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/14 14:55:59 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_add_back(t_stack **head, t_stack *new)
{
	t_stack	*temp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = stack_last(*head);
	temp -> next = new;
}

t_stack	*stack_last(t_stack *head)
{
	while (head != NULL && head -> next != NULL)
		head = head -> next;
	return (head);
}

t_stack	*stack_new(int content)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
