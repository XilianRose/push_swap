/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 13:44:34 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/31 11:53:44 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_wrapper(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	while (a != NULL && a->next != NULL)
// 	{
// 		ft_printf("stack a: [%i]\n", a->content);
// 		a = a->next;
// 	}
// 	if (a != NULL)
// 		ft_printf("stack a: [%i]\n", a->content);
// 	while (b != NULL && b->next != NULL)
// 	{
// 		ft_printf("stack b: [%i]\n", b->content);
// 		b = b->next;
// 	}
// 	if (b != NULL)
// 		ft_printf("stack b: [%i]\n", b->content);
// }
