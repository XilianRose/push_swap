/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 15:31:07 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/16 16:33:03 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_doubles(t_stack *a, int number)
{
	while (a->next != NULL)
	{
		if (a->content == number)
			return (ft_printf("Error\ninput contains doubles\n"), 1);
		a = a->next;
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
		while (argv[i])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' '
				|| ft_isdigit(argv[i][j]) == 0)
				j++;
			else
				return (1);
			i++;
		}
	}
	return (0);
}

// still have to check for over & underflow + test init & checks

int	stack_init(t_stack **a, int argc, char	**argv)
{
	t_stack	*node;
	char	**array;
	int		i;
	int		j;
	int		number;

	i = 1;
	while (i < argc)
	{
		array = ft_split(argv[i], ' ');
		j = 0;
		while (array)
		{
			number = ft_atoi(array[j]);
			if (check_doubles(*a, number) == 1)
				exit(1);
			node = stack_new(number);
			stack_add_front(a, node);
			j++;
		}
	}

}
