/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pivot.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 15:34:29 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/21 16:26:20 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	median_swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

static void	median_sort(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - i))
		{
			if (array[j] > array[j + 1])
				median_swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}

int	calculate_median(t_stack *a)
{
	int	*array;
	int	len;
	int	i;
	int	median;

	len = stack_size(a);
	array = ft_calloc(len + 1, sizeof(int));
	if (!array)
		exit_wrapper("failed to allocate for median calculation\n");
	i = 0;
	while (i < len)
	{
		array[i] = a->content;
		i++;
		a = a->next;
	}
	median_sort(array, len - 1);
	median = array[((len + 1) / 2) - 1];
	my_freestr((char *)array);
	return (median);
}

int	*calculate_pivots(t_stack *a)
{
	int	*pivot;
	int	*array;
	int	i;
	int	median;

	pivot = ft_calloc(3, sizeof(int));
	array = ft_calloc(stack_size(a) + 1, sizeof(int));
	if (!array || !pivot)
		exit_wrapper("failed to allocate for pivots calculation\n");
	i = 0;
	while (i < stack_size(a))
	{
		array[i] = a->content;
		i++;
		a = a->next;
	}
	median_sort(array, stack_size(a) - 1);
	median = ((stack_size(a) + 1) / 2) - 1;
	pivot[0] = array[median];
	pivot[1] = array[(median + 1 / 2) - 1];
	my_freestr((char *)array);
	return (pivot);
}
