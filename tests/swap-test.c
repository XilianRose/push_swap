/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap-test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 11:57:25 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/14 14:56:58 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(void)
{
	t_stack	*node;
	t_stack	**test;
	int		i;

	i = 0;
	test = ft_calloc(1, sizeof(t_list *));
	while (i < 5)
	{
		node = stack_new(i);
		if (!node)
			return (ft_printf("node alloc failed\n"));
		stack_add_back(test, node);
		i++;
	}
	node = *test;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
	sa(test);
	node = *test;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
	return (0);
}
