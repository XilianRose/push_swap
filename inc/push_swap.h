/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 15:46:53 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/20 10:25:09 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"

typedef struct s_stack {
	int				content;
	int				destination;
	struct s_stack	*next;
}	t_stack;

// parse & init

int			stack_init(t_stack **a, int argc, char	**argv);
int			check_chars(int argc, char **argv);

// sorting

int			calculate_median(t_stack *a);

//	operations

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);

void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// stack manipulation

void		stack_add_back(t_stack **head, t_stack *node);
void		stack_add_front(t_stack **head, t_stack *node);
int			stack_size(t_stack *node);
t_stack		*stack_last(t_stack *node);
t_stack		*stack_new(int content);

// utils

void		exit_wrapper(char *str);

#endif
