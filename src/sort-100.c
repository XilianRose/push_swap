/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort-100.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 10:40:48 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/23 15:58:48 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	sort_small(t_stack **a, t_stack **b)
// {
// 	int	size_a;
// 	int	size_b;
// 	int	pivot;

// 	size_a = stack_size(*a);
// 	while (size_a > 3)
// 	{
// 		pivot = calculate_median(*a);
// 		sort_a(a, b, size_a, pivot);
// 		size_a = stack_size(*a);
// 	}
// 	sort_three(a);
// 	size_b = stack_size(*b);
// 	while (size_b > 0)
// 	{
// 		pivot = calculate_median(*b);
// 		sort_b(b, a, size_b, pivot);
// 		size_b = stack_size(*b);
// 	}
// 	return ;
// }

// void	sort_big(t_stack **a, t_stack **b)
// {
// 	int	size_a;
// 	int	size_b;
// 	int	*pivots;

// 	size_a = stack_size(*a);
// 	while (size_a > 3)
// 	{
// 		pivots = calculate_pivots(*a);
// 		sort_a(a, b, size_a, pivots);
// 		size_a = stack_size(*a);
// 	}
// 	sort_three(a);
// 	size_b = stack_size(*b);
// 	while (size_b > 0)
// 	{
// 		pivots = calculate_pivots(*b);
// 		sort_b(b, a, size_b, pivots[0]);
// 		size_b = stack_size(*b);
// 	}
// 	return ;
// }
