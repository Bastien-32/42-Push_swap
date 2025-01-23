/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4_and_sort5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:47:17 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/23 09:57:47 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	search_min(t_node *a, int size)
{
	int	val_min;
	int	i;

	i = 0;
	val_min = INT_MAX;
	while (i < size)
	{
		if (val_min > a->content)
			val_min = a->content;
		a = a->next;
		i++;
	}
	return (val_min);
}

int	search_max(t_node *a, int size)
{
	int	val_max;
	int	i;

	i = 0;
	val_max = INT_MIN;
	while (i < size)
	{
		if (val_max < a->content)
			val_max = a->content;
		a = a->next;
		i++;
	}
	return (val_max);
}

void	sort5(t_node **a, t_node **b, int size, int i)
{
	int	val_min;
	int	val_max;

	if (size == 5)
	{
		val_min = search_min(*a, size);
		val_max = search_max(*a, size);
		while (i < 2)
		{
			if ((*a)->content == val_min || (*a)->content == val_max)
			{
				pb(a, b, 1);
				i++;
			}
			else
				ra(a, 1);
		}
		sort3(a, 3);
		while (*b)
		{
			pa(a, b, 1);
			if ((*a)->content > (*a)->next->content)
				ra(a, 1);
		}
	}
}

void	sort4(t_node **a, t_node **b, int size, int i)
{
	int	val_min;
	int	val_max;

	if (size == 4)
	{
		val_min = search_min(*a, size);
		val_max = search_max(*a, size);
		while (i < 1)
		{
			if ((*a)->content == val_min || (*a)->content == val_max)
			{
				pb(a, b, 1);
				i++;
			}
			else
				ra(a, 1);
		}
		sort3(a, 3);
		while (*b)
		{
			pa(a, b, 1);
			if ((*a)->content > (*a)->next->content)
				ra(a, 1);
		}
	}
}
