/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:14:07 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/09 16:32:24 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_node **a)
{
	t_node	*temp_i;
	t_node	*temp_j;
	int		i;

	temp_i = (*a)->next;
	while (temp_i)
	{
		temp_j = *a;
		i = 0;
		while (temp_j != temp_i)
		{
			if (temp_j->content < temp_i->content)
				update_lenghts(temp_i, temp_j, i);
			temp_j = temp_j->next;
			i++;
		}
		temp_i = temp_i->next;
		if (temp_i == *a)
			break ;
	}
}

void	is_in_lis(t_node **a)
{
	t_node	*temp_a;
	int		max_sub_sequence;
	int		next_subsequence;
  
	max_sub_sequence = find_max_sub_sequence(a);
	temp_a = *a;
	while (temp_a->lenght != max_sub_sequence)
		temp_a = temp_a->next;
	temp_a->in_lis = 1;
	next_subsequence = temp_a->sub_sequence;
	temp_a = temp_a->prev;
	fill_lis(next_subsequence, &temp_a);
}

void	pos_number(t_node **a)
{
	t_node	*current;
	t_node	*compare;
	int		position;

	current = *a;
	while (current)
	{
		position = 1;
		compare = *a;
		while (compare)
		{
			if (compare->content < current->content)
				position++;
			compare = compare->next;
			if (compare == *a)
				break ;
		}
		current->pos_number = position;
		current = current->next;
		if (current == *a)
			break ;
	}
}

void	first_sort(t_node **a, t_node **b, int size)
{
	int		i;
	t_node	*head;

	i = size;
	head = *a;
	while (i > 0)
	{
		if ((*a)->in_lis == 0)
		{
			pb(a, b, 1);
			if ((*b)->pos_number < size / 2)
				rb(b, 1);
		}
		else
		{
			ra(a, 1);
			if (*a == head)
				break ;
		}
		i--;
	}
}

void	second_sort(t_node **a, t_node **b)
{
	int		size_a;
	int		size_b;

	while (lstsize_ps(*b) > 0)
	{
		size_a = lstsize_ps(*a);
		size_b = lstsize_ps(*b);
		actualize_index(a);
		actualize_index(b);
		fill_num_moves_b(*b, size_b);
		fill_num_moves_a(*a, *b, size_a);
		sort_b_to_a(a, b);
	}
}
