/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 15:46:53 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/16 12:44:21 by mstegema      ########   odam.nl         */
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

//	operations
void		sa(t_stack **a);

void		ra(t_stack **a);

void		pa(t_stack **b, t_stack **a);

void		rra(t_stack **a);
// utils
void		stack_add_back(t_stack **head, t_stack *node);
void		stack_add_front(t_stack **head, t_stack *node);
int			stack_size(t_stack *node);
t_stack		*stack_last(t_stack *node);
t_stack		*stack_new(int content);
#endif
