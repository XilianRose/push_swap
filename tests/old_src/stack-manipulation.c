/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 14:46:40 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/19 13:36:22 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_add_back(t_stack **head, t_stack *node)
{
	t_stack	*temp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = stack_last(*head);
	temp -> next = node;
}

void	stack_add_front(t_stack **head, t_stack *node)
{
	node -> next = *head;
	*head = node;
}

int	stack_size(t_stack *node)
{
	int		res;
	t_stack	*current;

	res = 0;
	current = node;
	while (current != NULL)
	{
		current = current -> next;
		res++;
	}
	return (res);
}

t_stack	*stack_last(t_stack *node)
{
	while (node != NULL && node -> next != NULL)
		node = node -> next;
	return (node);
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
