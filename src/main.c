/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 16:30:42 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/17 14:42:47 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// still have to test init & checks

int	stack_init(t_stack **a, int argc, char	**argv)
{
	t_stack	*node;
	char	**array;
	int		i;
	int		j;
	long	number;

	i = 1;
	while (i < argc)
	{
		array = ft_split(argv[i], ' ');
		j = 0;
		while (array)
		{
			number = my_atol(array[j]);
			if (number < INT32_MIN || number > INT32_MAX)
				exit(1);
			if (check_doubles(*a, number) == 1)
				exit(1);
			node = stack_new(number);
			stack_add_front(a, node);
			j++;
		}
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*node;

	if (argc == 1)
		return (1);
	if (check_chars(argc, argv) == 1)
		return (ft_printf("Error\nNot valid input\n"), 1);
	a = ft_calloc(1, sizeof(t_list *));
	b = ft_calloc(1, sizeof(t_list *));
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
	pa(b, a);
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
