/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 15:20:56 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	printlist(t_node *temp_a, t_node *temp_b)
{
	while (temp_a || temp_b)
	{
		if (temp_a && temp_b)
		{
			printf("%d  %d\n", temp_a->content, temp_b->content);
			temp_a = temp_a->next;
			temp_b = temp_b->next;
		}
		else if (temp_a)
		{
			printf("%d     \n", temp_a->content);
			temp_a = temp_a->next;
		}
		else if (temp_b)
		{
			printf("     %d\n", temp_b->content);
			temp_b = temp_b->next;
		}
	}
	printf("-   -\n");
	printf("a   b\n");
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	t_node 	*a;
	t_node 	*b;
	int 	size;
	
	a = NULL;
	b = NULL;
	if (!check_args(argc, argv))
	{
		init_stack(argc, argv, &a);
		check_stack(&a);
		size = lstsize(a);
		sort(&a, &b, size);
		
		t_node	*temp_a;
		t_node	*temp_b;
		printf("Listes après tri : \n");
		temp_a = a;
		temp_b = b;
		printlist(temp_a, temp_b);
		
		/* free_split(split_argv); 
		gros doute sur le fait que ce soit free avant...*/
	}
	else
		write(1, "Error\n", 6);
}

/* 
//test commandes
int	main(int argc, char *argv[])
{
	int		i = 1;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*temp_a;
	t_node	*temp_b;
	
	if (argc <= 1)
	{
		write(1, "Error", 5);
		return (1);
	}
	while (argv[i])
	{
		if (!is_number(argv[i]))
		{
			write(1, "Error", 5);
			return (1);
		}
		i++;
	}
	
	stack_a = ft_lstnew(atoi(argv[1]));
	stack_b = NULL;
	i = 2;
	while (argv[i])
	{
		temp_a = ft_lstnew(atoi(argv[i]));
		ft_lstadd_back(&stack_a, temp_a);
		i++;
	}
	printf("Listes avant tri : \n");
	temp_a = stack_a;
	temp_b = stack_b;
	printlist(temp_a, temp_b);

	sa(&stack_a, 1);
	temp_a = stack_a;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);

	ra(&stack_a, 1);
	temp_a = stack_a;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);

	pb(&stack_a, &stack_b, 1);
	temp_a = stack_a;
	temp_b = stack_b;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);

	pb(&stack_a, &stack_b, 1);
	pb(&stack_a, &stack_b, 1);
	pb(&stack_a, &stack_b, 1);
	temp_a = stack_a;
	temp_b = stack_b;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);

	rb(&stack_b, 1);
	temp_b = stack_b;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);
	return (0);
} */