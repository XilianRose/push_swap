/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 13:44:34 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/19 13:49:18 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_wrapper(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
