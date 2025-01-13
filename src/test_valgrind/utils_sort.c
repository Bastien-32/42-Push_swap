/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:58:17 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/09 12:31:55 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_lenghts(t_node *temp_i, t_node *temp_j, int i)
{
	int		temp_lenght;

	temp_lenght = temp_j->lenght + 1;
	if (temp_lenght >= temp_i->lenght)
	{
		temp_i->lenght = temp_lenght;
		if (i >= temp_i->sub_sequence)
			temp_i->sub_sequence = i;
	}
}

int	find_max_sub_sequence(t_node **a)
{
	t_node	*temp_a;
	int		max_sub_sequence;

	temp_a = *a;
	max_sub_sequence = temp_a->lenght;
	while (temp_a)
	{
		if (temp_a->lenght > max_sub_sequence)
			max_sub_sequence = temp_a->lenght;
		temp_a = temp_a->next;
		if (temp_a == *a)
			break ;
	}
	return (max_sub_sequence);
}

void	fill_lis(int next_subsequence, t_node **a)
{
	t_node	*temp_a;

	temp_a = *a;
	while (1)
	{
		if (temp_a->index == next_subsequence && temp_a->lenght == 1)
		{
			temp_a->in_lis = 1;
			break ;
		}
		else if (temp_a->index == next_subsequence)
		{
			temp_a->in_lis = 1;
			next_subsequence = temp_a->sub_sequence;
			temp_a = temp_a->prev;
		}
		else
			temp_a = temp_a->prev;
	}
}

void	move_first_num_on_top(t_node **a)
{
	t_node	*temp_a;
	int		pos_number_in_a;

	pos_number_in_a = 0;
	temp_a = *a;
	if (temp_a->pos_number != 1)
	{
		while (temp_a->pos_number != 1)
		{
			pos_number_in_a += 1;
			temp_a = temp_a->next;
		}
		if (pos_number_in_a < lstsize_ps(*a) / 2)
		{
			while (pos_number_in_a-- > 0)
				ra (a, 1);
		}
		else
		{
			while (lstsize_ps(*a) - pos_number_in_a++ > 0)
				rra (a, 1);
		}
	}
}
