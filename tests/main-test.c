/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main-test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 13:50:39 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/19 13:51:13 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char	**argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*node;

	if (argc == 1)
		return (1);
	if (check_chars(argc, argv) == 1)
		return (ft_printf("Error\nNot valid input\n"), 1);
	a = NULL;
	b = NULL;
	stack_init(&a, argc, argv);
		// printf test a before operation
	ft_printf("stack a before: \n");
	node = a;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
		// printf test b before operation
	ft_printf("stack a before: \n");
	node = b;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
		// operation
	pa(&b, &a);
		// printf test a after operation
	ft_printf("stack a after: \n");
	node = a;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
		// printf test b after operation
	ft_printf("stack b after: \n");
	node = b;
	while (node)
	{
		ft_printf("content: %d	address: %p\n", node->content, node);
		node = node->next;
	}
	return (0);
}
