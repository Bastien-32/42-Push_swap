/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:21:46 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/09 18:00:27 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actualize_index(t_node **b)
{
	t_node	*temp_b;
	int		i;

	i = 0;
	temp_b = *b;
	while (temp_b)
	{
		temp_b->index = i;
		temp_b = temp_b->next;
		if (temp_b == *b)
			break ;
		i++;
	}
}

void	fill_num_moves_b(t_node *b, int size_b)
{
	t_node	*temp_b;

	temp_b = b;
	while (temp_b)
	{
		if (temp_b->index <= size_b / 2)
			temp_b->compt_b = temp_b->index;
		else
			temp_b->compt_b = temp_b->index - size_b;
		temp_b = temp_b->next;
		if (temp_b == b)
			break ;
	}
}

t_node	*search_pos_b_in_a(t_node *a, t_node *temp_b)
{
	t_node	*temp_a;

	temp_a = a;
	while (temp_a)
	{
		if (temp_b->pos_number > temp_a->prev->pos_number
			&& temp_b->pos_number < temp_a->pos_number)
			break ;
		if (temp_a->prev->pos_number > temp_a->pos_number
			&& (temp_b->pos_number > temp_a->prev->pos_number
				|| temp_b->pos_number < temp_a->pos_number))
			break ;
		temp_a = temp_a->next;
		if (temp_a == a)
			break ;
	}
	return (temp_a);
}

void	fill_num_moves_a(t_node *a, t_node *b, int size_a)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = a;
	temp_b = b;
	while (temp_b)
	{
		temp_a = search_pos_b_in_a(a, temp_b);
		if (temp_a->index < size_a / 2)
			temp_b->compt_a = temp_a->index;
		else if (temp_a->index == size_a / 2)
		{
			if (temp_b->compt_b > 0)
				temp_b->compt_a = temp_a->index;
			else
				temp_b->compt_a = -temp_a->index;
		}
		else
			temp_b->compt_a = temp_a->index - size_a;
		cheapest(temp_b);
		temp_b = temp_b->next;
		if (temp_b == b)
			break ;
	}
}

void	sort_b_to_a(t_node **a, t_node **b)
{
	t_node	*temp_b;
	int		cheapest;

	temp_b = *b;
	// printf("=========================================\n");
	// 	printf("list a before sort b2a=\n");
	// 	printlist(a);
	// 	printf("list b before sort b2a=\n");
	// 	printlist(b);
	// 	printf("=========================================\n");
	cheapest = search_cheapest(&temp_b);
	//printf("cheaest= %d\n", cheapest);
	if (temp_b->cheapest != cheapest)
	{
		while (temp_b->cheapest != cheapest)
			temp_b = temp_b->next;
	}
	//printf("uhu\n");
	move_number(a, b, temp_b->compt_a, temp_b->compt_b);
}
