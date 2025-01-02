/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:53:38 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 16:15:48 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	*reverse_rotate(t_node **stack)
{
	t_node	*previous;
	t_node	*last;

	previous = NULL;
	last = *stack;
	if (!stack || !(*stack)->next || !*stack)
		return(*stack);
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *stack;
	*stack = last;
	return (*stack);
}

void	rra(t_node **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}
void	rrr(t_node **a, t_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
