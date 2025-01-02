/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:57:19 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 16:14:19 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (!dest)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest;
		*dest = temp;
	}
}

void	pa(t_node **a, t_node **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}
void	pb(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}
