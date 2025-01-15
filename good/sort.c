/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:00:09 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/15 17:51:19 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			ra(a, 1);
	}
	sort3(a, size);
	big_sorts(a, b, size);
}

void	sort3(t_node **a, int size)
{
	if (size == 3)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, 1);
		if ((*a)->content > (*a)->next->next->content)
			rra(a, 1);
		if ((*a)->next->content > (*a)->next->next->content)
		{
			sa(a, 1);
			ra(a, 1);
		}
	}
}

void	big_sorts(t_node **a, t_node **b, int size)
{
	if (size > 3)
	{
		lis(a);
		is_in_lis(a);
		pos_number(a);
		first_sort(a, b, size);
		second_sort(a, b);
		move_first_num_on_top(a);
	}
}

search_min(a)
{
	int val_min;

	val_min = INT_MAX;
	while (a)
	if val_min > a->content
		val_min = a->content
	
}

void	sort5(t_node **a, t_node **b, int size)
{
	if (size == 5)
	{
		val min = search_min(a);
		val max = 
	while a 
	si cont = min ou cont = max =>pb
	sort3
	while b
	pb 
	si a cont = max => ra
	}
}
