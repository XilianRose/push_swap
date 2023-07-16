/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 15:46:53 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/16 16:20:41 by mstegema      ########   odam.nl         */
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

int			check_chars(int argc, char **argv);

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

// utils

void		stack_add_back(t_stack **head, t_stack *node);
void		stack_add_front(t_stack **head, t_stack *node);
int			stack_size(t_stack *node);
t_stack		*stack_last(t_stack *node);
t_stack		*stack_new(int content);
#endif
