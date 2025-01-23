/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:19:55 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/22 16:39:15 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap(t_node **stack)
{
	t_node	*swap;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != *stack)
		last = last->next;
	swap = (*stack)->next;
	(*stack)->next = swap->next;
	if (swap->next)
		swap->next->prev = *stack;
	swap->next = *stack;
	swap->prev = last;
	(*stack)->prev = swap;
	*stack = swap;
	last->next = *stack;
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
