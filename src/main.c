/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 16:30:42 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/23 15:51:46 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char	**argv)
{
	t_stack		*a;
	t_stack		*b;
	t_pivots	*pivots;

	if (argc == 1)
		return (1);
	if (check_chars(argc, argv) == 1)
		return (ft_printf("Error\ninvalid input\n"), 1);
	a = NULL;
	b = NULL;
	pivots = NULL;
	stack_init(&a, argc, argv);
	if (stack_size(a) <= 500)
		sort_small(&a, &b);
	// else
		// sort_big(&a, &b);
	return (0);
}
