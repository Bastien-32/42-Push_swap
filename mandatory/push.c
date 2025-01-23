/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:27:25 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/22 16:43:02 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	temp = *src;
	*src = (*src)->next;
	if (*src == temp)
		*src = NULL;
	else
	{
		(*src)->prev = temp->prev;
		temp->prev->next = *src;
	}
	if (!*dest)
	{
		*dest = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *dest;
		temp->prev = (*dest)->prev;
		(*dest)->prev->next = temp;
		(*dest)->prev = temp;
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
