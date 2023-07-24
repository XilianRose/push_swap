/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pivot.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 15:34:29 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/24 12:40:51 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	median_sort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - i))
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*init_median_array(t_stack *a, int len)
{
	int	*array;
	int	i;

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
	return (array);
}

int	calculate_median(t_stack *a)
{
	int	*array;
	int	len;
	int	median;

	len = stack_size(a);
	array = init_median_array(a, len);
	median = array[((len + 1) / 2) - 1];
	my_freestr((char *)array);
	return (median);
}

t_pivots	calculate_3_pivots(t_stack *a, t_pivots *pivots)
{
	int	*array;
	int	len;
	int	median;
	int	half_median;

	len = stack_size(a);
	array = init_median_array(a, len);
	median = ((len + 1) / 2) - 1;
	half_median = ((median + 1) / 2) - 1;
	pivots->pivot[0] = array[0];
	pivots->pivot[1] = array[half_median];
	pivots->pivot[2] = array[median];
	pivots->pivot[3] = array[median + half_median];
	pivots->pivot[4] = array[len - 1];
	my_freestr((char *)array);
	return (*pivots);
}

t_pivots	calculate_7_pivots(t_stack *a, t_pivots *pivots)
{
	int	*array;
	int	len;
	int	median;
	int	half_median;
	int	quart_median;

	len = stack_size(a);
	array = init_median_array(a, len);
	median = ((len + 1) / 2) - 1;
	half_median = ((median + 1) / 2) - 1;
	quart_median = ((half_median + 1) / 2) - 1;
	pivots->pivot[0] = array[0];
	pivots->pivot[1] = array[quart_median];
	pivots->pivot[2] = array[half_median];
	pivots->pivot[3] = array[half_median + quart_median];
	pivots->pivot[4] = array[median];
	pivots->pivot[5] = array[median + quart_median];
	pivots->pivot[6] = array[median + half_median];
	pivots->pivot[7] = array[median + half_median + quart_median];
	pivots->pivot[8] = array[len - 1];
	my_freestr((char *)array);
	return (*pivots);
}
