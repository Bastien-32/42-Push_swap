/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/12 11:10:35 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_node **list)
{
	t_node	*tl;

	tl = *list;
	printf("n    a    b    c    p    i\n");
	while (tl)
	{
		printf("%d    %d    %d    %d    %d    %d\n", tl->content, tl->compt_a, tl->compt_b, tl->cheapest, tl->pos_number, tl->index);
		tl = tl->next;
		if (tl == *list)
			break;
	}
}
void	printlistlis(t_node **list)
{
	t_node	*tl;

	tl = *list;
	printf("n    i    l    s    i    p\n");
	while (tl)
	{
		printf("%d    %d    %d    %d    %d    %d\n", tl->content, tl->index , tl->lenght, tl->sub_sequence, tl->in_lis, tl->pos_number);
		tl = tl->next;
		if (tl == *list)
			break;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		size_a;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else
	{
		if (!check_args(argc, argv))
		{
			init_stack(argc, argv, &a);
			size_a = lstsize_ps(a);
			check_stack(&a, size_a);
			sort(&a, &b, size_a);
			printlist(&a);
		}
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
