/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/25 17:58:12 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

/* #include <unistd.h>
#include <stdlib.h> */
#include <stdio.h>
/* 
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_pslist;

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	return ((int)result);
}
 */
t_pslist	*sa_ps(t_pslist *stack)
{
    t_pslist  *swap;

    if (!stack || !stack->next)
        return (stack);
    swap = stack->next;
    stack->next = swap->next;
    swap->next = stack;
    return (swap);
}

t_pslist	*rra_ps(t_pslist **stack)
{
	t_pslist *previous;
    t_pslist  *last;

	previous = NULL;
	last = *stack;
    if (!stack || !(*stack)->next || !*stack)
        return(*stack);
    while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *stack;
	*stack = last;
	return (*stack);
}

void	ra_ps(t_pslist **stack)
{
    t_pslist  *last;
	t_pslist	*swap;
	t_pslist	*first;

	last = *stack;
	first = *stack;
    if (!stack || !(*stack)->next || !*stack)
        return;
    while (last->next)
		last = last->next;
	swap = first->next;
	last->next = first;
	first->next = NULL;
	*stack = swap;
}
void	pb_ps(t_pslist **stack_a, t_pslist **stack_b)

{
	t_pslist	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, temp);
}

void	printlist(t_pslist *temp_a, t_pslist *temp_b)
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

int	main(int argc, char *argv[])
{
	int		i = 1;
	t_pslist	*stack_a;
	t_pslist	*stack_b;
	t_pslist	*temp_a;
	t_pslist	*temp_b;

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

	stack_a = sa_ps(stack_a);
	temp_a = stack_a;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);

	ra_ps(&stack_a);
	temp_a = stack_a;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);

	pb_ps(&stack_a, &stack_b);
	temp_a = stack_a;
	temp_b = stack_b;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);

	pb_ps(&stack_a, &stack_b);
	pb_ps(&stack_a, &stack_b);
	pb_ps(&stack_a, &stack_b);
	temp_a = stack_a;
	temp_b = stack_b;
	printf("Listes après tri : \n");
	printlist(temp_a, temp_b);
	return (0);
}