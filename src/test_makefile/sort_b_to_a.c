/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:42:08 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/08 17:36:37 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest(t_node *b)
{
	if (b->compt_a <= 0 && b->compt_b <= 0)
	{
		if (b->compt_a < b->compt_b)
			b->cheapest = b->compt_a;
		else
			b->cheapest = b->compt_b;
	}
	else if (b->compt_a >= 0 && b->compt_b >= 0)
	{
		if (b->compt_a < b->compt_b)
			b->cheapest = b->compt_b;
		else
			b->cheapest = b->compt_a;
	}
	else if (b->compt_a <= 0 && b->compt_b >= 0)
		b->cheapest = b->compt_b - b->compt_a;
	else if (b->compt_a >= 0 && b->compt_b <= 0)
		b->cheapest = b->compt_a - b->compt_b;
}

int	cheapest_cond(int cheapest)
{
	if (cheapest == 0)
		return (0);
	if (cheapest == 1)
		return (1);
	return (-1);
}

int	search_cheapest(t_node **b)
{
	t_node	*temp_b;
	int		cheapest;

	temp_b = *b;
	cheapest = temp_b->cheapest;
	while (temp_b)
	{
		if (cheapest >= -1 && cheapest <= 1)
		{
			cheapest = cheapest_cond(temp_b->cheapest);
			return (cheapest);
		}
		if (temp_b->cheapest < -1
			&& ((cheapest > 1 && temp_b->cheapest < cheapest)
				|| (cheapest < -1 && temp_b->cheapest < -cheapest)))
			cheapest = temp_b->cheapest;
		else if (temp_b->cheapest > 1
			&& ((cheapest < -1 && temp_b->cheapest < -cheapest)
				|| (cheapest > 1 && temp_b->cheapest < cheapest)))
			cheapest = temp_b->cheapest;
		temp_b = temp_b->next;
		if (temp_b == *b)
			break ;
	}
	return (cheapest);
}

void	move_number(t_node **a, t_node **b, int compt_a, int compt_b)
{
	if (compt_b == 0 && compt_a == 0)
		pa(a, b, 1);
	else if (compt_a <= 0 && compt_b <= 0)
		move_ab_neg(a, b, compt_a, compt_b);
	else if (compt_a >= 0 && compt_b >= 0)
		move_ab_pos(a, b, compt_a, compt_b);
	else
		move_ab_sign_diff(a, b, compt_a, compt_b);
}
