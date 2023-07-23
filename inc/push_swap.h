/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 15:46:53 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/23 23:05:11 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"

typedef struct s_pivots{
	int				pivot[10];
	bool			rb;
}	t_pivots;

typedef struct s_price{
	int				r;
	int				rr;
}	t_price;

typedef struct s_stack {
	int				content;
	struct s_stack	*next;
	t_price			cost;
}	t_stack;

// parse & init

int			stack_init(t_stack **a, int argc, char	**argv);
int			check_chars(int argc, char **argv);

// sorting

void		sort_three(t_stack **a);
void		sort_small(t_stack **a, t_stack **b);
void		sort_big(t_stack **a, t_stack **b);

int			find_node(t_stack **a, int pivot);
int			find_node_between(t_stack **a, t_pivots *pivots, int r1, int r2);
int			phase_two_find_node(t_stack **b, int size);
void		phase_one_push(t_stack **a, t_stack **b, int node_index);
void		phase_two_push(t_stack **a, t_stack **b, int node_index);

int			calculate_median(t_stack *a);
t_pivots	calculate_3_pivots(t_stack *a, t_pivots *pivots);
t_pivots	calculate_5_pivots(t_stack *a, t_pivots *pivots);

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
void		print_stacks(t_stack *a, t_stack *b);

#endif
