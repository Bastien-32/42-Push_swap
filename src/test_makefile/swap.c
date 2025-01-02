/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:56:10 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 16:17:13 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	swap(t_node **stack)
{
    t_node  *swap;

    if (!*stack || !(*stack)->next)
        return;
    swap = (*stack)->next;
    (*stack)->next = swap->next;
    swap->next = *stack;
	*stack = swap;
}

void	sa(t_node **a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
