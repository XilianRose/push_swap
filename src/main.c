/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 16:30:42 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/24 12:49:10 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char	**argv)
{
	t_stack		*a;
	t_stack		*b;
	t_pivots	pivots;

	if (argc == 1)
		return (1);
	if (check_chars(argc, argv) == 1)
		return (ft_printf("Error\ninvalid input\n"), 1);
	a = NULL;
	b = NULL;
	stack_init(&a, argc, argv);
	if (stack_size(a) < 50)
		sort_small(&a, &b);
	else if (stack_size(a) < 100)
		sort_100(&a, &b, &pivots);
	else if ((stack_size(a) >= 100))
		sort_500(&a, &b, &pivots);
	return (0);
}
