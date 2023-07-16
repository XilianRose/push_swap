/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push-test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 12:01:47 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/16 15:15:22 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	gcc -Wall -Wextra -Werror -g push-test.c ../src/push.c ../libft/bin/libft.a
	../src/utils.c
*/

int	main(void)
{
	t_stack	*node;
	t_stack	**test_a;
	t_stack	**test_b;
	int		i;

	// alloc & init test a
	i = 0;
	test_a = ft_calloc(1, sizeof(t_list *));
	while (i < 5)
	{
		node = stack_new(i);
		if (!node)
			return (ft_printf("node alloc failed\n"));
		stack_add_back(test_a, node);
		i++;
	}
	// printf test a before operation
	ft_printf("stack a before: \n");
	node = *test_a;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
	// alloc & init test b
	i = 5;
	test_b = ft_calloc(1, sizeof(t_list *));
	while (i < 10)
	{
		node = stack_new(i);
		if (!node)
			return (ft_printf("node alloc failed\n"));
		stack_add_back(test_b, node);
		i++;
	}
	// printf test b before operation
	ft_printf("stack a before: \n");
	node = *test_b;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
	// operation
	pa(test_b, test_a);
	// printf test a after operation
	ft_printf("stack a after: \n");
	node = *test_a;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
	// printf test b after operation
	ft_printf("stack b after: \n");
	node = *test_b;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
	return (0);
}
