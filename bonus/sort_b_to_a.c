/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:42:08 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/22 16:38:59 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
	if (b->cheapest < 0)
		b->cheapest *= -1;
}

int	search_cheapest(t_node **b)
{
	t_node	*temp_b;
	int		cheapest;

	temp_b = *b;
	cheapest = temp_b->cheapest;
	while (1)
	{
		if (cheapest == 0 || cheapest == 1)
			break ;
		if (temp_b->cheapest < cheapest)
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
