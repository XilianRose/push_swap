/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 15:31:07 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/21 10:22:16 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_doubles(t_stack *a, int number)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->content == number)
			return (1);
		a = a->next;
	}
	return (0);
}

int	stack_init(t_stack **a, int argc, char	**argv)
{
	t_stack	*node;
	char	**array;
	int		i;
	int		j;
	long	number;

	i = 1;
	while (i < argc)
	{
		array = ft_split(argv[i], ' ');
		j = 0;
		while (array[j] != '\0')
		{
			number = my_atol(array[j]);
			if (number < INT32_MIN || number > INT32_MAX)
				exit_wrapper("input is out of integer range");
			if (check_doubles(*a, number) == 1)
				exit_wrapper("input contains doubles");
			node = stack_new(number);
			stack_add_back(a, node);
			j++;
		}
		i++;
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
