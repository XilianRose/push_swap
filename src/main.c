/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 16:30:42 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/31 11:52:58 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// static void check_leaks(void)
// {
// 	system("leaks push_swap");
// }
// 	atexit(check_leaks);

int	main(int argc, char	**argv)
{
	t_stack		*a;
	t_stack		*b;
	t_pivots	pivots;

	if (argc == 1)
		return (1);
	if (check_chars(argc, argv) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	a = NULL;
	b = NULL;
	stack_init(&a, argc, argv, 1);
	if (check_sorted(a) == 0)
		exit(0);
	if (stack_size(a) < 50)
		sort_small(&a, &b);
	else if (stack_size(a) < 100)
		sort_100(&a, &b, &pivots);
	else if ((stack_size(a) >= 100))
		sort_500(&a, &b, &pivots);
	exit(0);
}
