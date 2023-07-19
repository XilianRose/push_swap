/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 16:30:42 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/19 16:46:58 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char	**argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	if (check_chars(argc, argv) == 1)
		return (ft_printf("Error\ninvalid input\n"), 1);
	a = NULL;
	b = NULL;
	stack_init(&a, argc, argv);
	calculate_median(a);
	return (0);
}
