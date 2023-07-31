/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 15:31:07 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/31 11:54:46 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	check_doubles(t_stack *a, int number)
{
	while (a != NULL)
	{
		if (a->content == number)
			return (1);
		a = a->next;
	}
	return (0);
}

int	stack_init(t_stack **a, int argc, char	**argv, int i)
{
	t_stack	*node;
	char	**array;
	int		j;
	long	number;

	while (i < argc)
	{
		array = ft_split(argv[i], ' ');
		j = 0;
		while (array[j] != NULL)
		{
			number = my_atol(array[j]);
			if (number < INT32_MIN || number > INT32_MAX)
				exit_wrapper("Error\n");
			if (check_doubles(*a, number) == 1)
				exit_wrapper("Error\n");
			node = stack_new(number);
			stack_add_back(a, node);
			j++;
		}
		i++;
		my_freearray(array);
	}
	return (0);
}

int	check_chars(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' '
				|| ft_isdigit(argv[i][j]) == 1)
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
