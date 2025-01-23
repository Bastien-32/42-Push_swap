/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:53:01 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/22 16:38:32 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	move_ab_neg(t_node **a, t_node **b, int compt_a, int compt_b)
{
	if (compt_a != 0 && compt_b != 0)
	{
		while (compt_a < 0 && compt_b < 0)
		{
			rrr(a, b, 1);
			compt_a++;
			compt_b++;
		}
	}
	if (compt_a == 0)
	{
		while (compt_b++ < 0)
			rrb(b, 1);
		pa(a, b, 1);
	}
	else
	{
		while (compt_a++ < 0)
			rra(a, 1);
		pa(a, b, 1);
	}
}

void	move_ab_pos(t_node **a, t_node **b, int compt_a, int compt_b)
{
	if (compt_a != 0 && compt_b != 0)
	{
		while (compt_a > 0 && compt_b > 0)
		{
			rr(a, b, 1);
			compt_a--;
			compt_b--;
		}
	}
	if (compt_a == 0 && compt_b == 0)
		pa(a, b, 1);
	else
	{
		if (compt_a == 0 && compt_b != 0)
		{
			while (compt_b-- > 0)
				rb(b, 1);
		}
		else if (compt_b == 0 && compt_a != 0)
		{
			while (compt_a-- > 0)
				ra(a, 1);
		}
		pa(a, b, 1);
	}
}

void	move_ab_sign_diff(t_node **a, t_node **b, int compt_a, int compt_b)
{
	if (compt_b < 0)
	{
		while (compt_b++ < 0)
			rrb(b, 1);
	}
	else
	{
		while (compt_b-- > 0)
			rb(b, 1);
	}
	if (compt_a < 0)
	{
		while (compt_a++ < 0)
			rra(a, 1);
	}
	else
	{
		while (compt_a-- > 0)
			ra(a, 1);
	}
	pa(a, b, 1);
}
