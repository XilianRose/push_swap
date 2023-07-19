/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 15:34:29 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/19 16:54:52 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	median_swap(int *first, int *second)
{
	int	*temp;

	temp = first;
	first = second;
	second = temp;
}

void	median_sort(int *array, int len)
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
	ft_printf("after sort: \n");
	i = 0 ;
	while (i < len + 1)
	{
		ft_printf("array[%i] = %i\n", i, array[i]);
		i++;
	}
}

int	calculate_median(t_stack *a)
{
	int	*array;
	int	len;
	int	i;
	int	median;
	int	res;

	len = stack_size(a);
	array = ft_calloc(len + 1, sizeof(int));
	i = 0;
	while (i < len)
	{
		array[i] = a->content;
		i++;
		a = a->next;
	}
	i = 0;
	while (i < len)
	{
		ft_printf("array[%i] = %i\n", i, array[i]);
		i++;
	}
	median_sort(array, len - 1);
	median = ((len + 1)/2) - 1;
	res = array[median];
	ft_printf("median = %i\n", res);
	return (0);
}
