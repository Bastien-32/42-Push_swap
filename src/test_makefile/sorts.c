/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:18:24 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 16:27:44 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, 1);
	}
	sort3(a, size);
	sort5(a, b, size);
	//sort10(&a, size);
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
void	sort5(t_node **a, t_node **b, int size)
{
	if (size == 5)
	{
		pa(a, b, 1);
	}
}

/* void	sort10(t_node **a, int size)
{
	if (size < 10)
	{
		
	}
} */

