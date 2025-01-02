/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:47:59 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 16:16:47 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
    t_node  *last;
	t_node	*swap;
	t_node	*first;

	last = *stack;
	first = *stack;
	if (!stack || !(*stack)->next || !*stack)
		return;
	while (last->next)
		last = last->next;
	swap = first->next;
	last->next = first;
	first->next = NULL;
	*stack = swap;
}

void	ra(t_node **a, int print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}
void	rb(t_node **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
