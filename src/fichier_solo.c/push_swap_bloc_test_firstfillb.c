/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bloc_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/04 11:32:45 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h"
#include "ft_printf.h"
#include "push_swap.h" */

#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>
#include <limits.h>

typedef struct s_node
{
	int				content;
	int 			lenght;
	int				pos_number;
	int 			sub_sequence;
	int				index;
	int 			in_lic;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->lenght = 1;
	node->sub_sequence = 0;
	node->in_lic = 0;
	node->prev = NULL;	
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->index = last->index + 1;
	new->prev = last;
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
 
void	swap(t_node **stack)
{
    t_node  *swap;

    if (!*stack || !(*stack)->next)
        return;
    swap = (*stack)->next;
    (*stack)->next = swap->next;
    swap->next = *stack;
	*stack = swap;
}
void sa(t_node **a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}
void sb(t_node **b, int print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}
void ss(t_node **a, t_node **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}

void	*reverse_rotate(t_node **stack)
{
	t_node *previous;
    t_node  *last;

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
void rra(t_node **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}
void rrb(t_node **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}
void rrr(t_node **a, t_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}

void	rotate(t_node **stack)
{
    t_node  *last;
	t_node	*swap;
	t_node	*first;

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
void ra(t_node **a, int print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}
void rb(t_node **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}
void rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (!dest)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest;
		*dest = temp;
	}
}
void	pa(t_node **a, t_node **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}
void	pb(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}

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

int	nwords(char *str, char separator)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != separator && (i == 0 || str[i - 1] == separator))
			count++;
		i++;
	}
	return (count);
}

int	lenword(char *str, int i, char separator)
{
	int count;

	count = 0;
	while (str[i + count] && str[i + count] != separator)
		count++;
	return (count);
}

static char	**free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char separator)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (nwords(str, separator) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] != separator)
		{
			tab[j] = ft_substr(str, i, lenword(str, i, separator));
			if (!tab[j])
				return (free_split(tab));
			j++;
			i += lenword(str, i, separator);
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	is_number(const char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && !((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			return (0);
	}
	return (1);
}

char	**parse_args(int argc, char **argv)
{
	char		**split_argv;
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (NULL);
		return (split_argv);
	}
		return (argv + 1);
}

int check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc == 1)
		return (1);
	while (argv[i])
	{	
		if (!is_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	init_stack(int argc, char **argv, t_node **a)
{
	int		i;
	char	**split_argv;
	
	if (argc == 2)
		split_argv = parse_args(argc, argv);
	else
		split_argv = argv + 1;
	*a = ft_lstnew(ft_atoi(split_argv[0]));
	(*a)->index = 0;
	i = 1;
	while (split_argv[i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(split_argv[i++])));
}

int a_is_sorted(t_node **a)
{
	t_node	*temp;
	
	temp = *a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	a_contain_doubles(t_node **a)
{
	t_node	*temp;
	t_node	*temp2;
	
	temp = *a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->content == temp2->content)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	check_stack(t_node **a)
{
	if (a_is_sorted(a))
		exit (-1);
	if (a_contain_doubles(a))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	lstsize(t_node *lst)
{
	int		i;
	
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
/* void	sort5(t_node **a, t_node **b, int size)
{
	t_node	*temp_a;
	
	temp_a = *a;
	if (size == 5)
	{
		while (temp_a && temp_a->content > (*a)->content)
		{
		
		}
	}
} */
/* void	sort10(t_node **a, int size)
{
	if (size < 10)
	{
		
	}
} */

void update_lenghts(t_node *temp_i, t_node *temp_j, int i)
{
	int 	temp_lenght;
	temp_lenght = temp_j->lenght + 1;
	if(temp_lenght >= temp_i->lenght)
	{
		temp_i->lenght = temp_lenght;
		if(i >= temp_i->sub_sequence)
			temp_i->sub_sequence = i;
	}
}

void lic(t_node **a)
{
	t_node	*temp_i;
	t_node	*temp_j;
	int 	temp_lenght;
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
	}
}

int	find_max_sub_sequence(t_node **a)
{
	t_node 	*temp_a;
	int		max_sub_sequence;

	max_sub_sequence = temp_a->lenght;	
	while (temp_a)
	{
		if (temp_a->lenght > max_sub_sequence)
			max_sub_sequence = temp_a->lenght;
		temp_a = temp_a->next;
	}
	return(max_sub_sequence);
}

void	fill_lic(int index, int next_subsequence, t_node *temp_a, int temp)
{
	while (1)
	{
		if (temp_a->index == next_subsequence)
		{
			temp_a->in_lic = 1;
			next_subsequence = temp_a->sub_sequence;
		}
		if (temp_a->index == next_subsequence && temp_a->sub_sequence == 0)
		{
			if (temp_a->index != 0)
			{
				temp = temp_a->content;
				while (temp_a)
				{
					if (temp_a->prev == NULL)
						break;
					temp_a = temp_a->prev;
				}
				if (temp_a->content < temp)
					temp_a->in_lic = 1;
			}
			break;
		}
		temp_a = temp_a->prev;
	}
}

void	is_in_lic(t_node **a)
{
	t_node	*temp_a;
	int		max_sub_sequence;
	int		next_subsequence;
	int		temp;

	temp = 0;
	max_sub_sequence = find_max_sub_sequence(a);
	temp_a = *a;
	while (temp_a->lenght != max_sub_sequence)
		temp_a = temp_a->next;
	temp_a->in_lic = 1;
	next_subsequence = temp_a->sub_sequence;
	temp_a = temp_a->prev;
	fill_lic(temp_a->index, next_subsequence, temp_a, temp);
}

void pos_number(t_node **a)
{
    t_node *current;
    t_node *compare;
    int position;

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
        }
        current->pos_number = position;
        current = current->next;
    }
}

void	first_sort(t_node **a, t_node **b, int size)
{
	int	i;
	
	i = size;
	while (i--)
	{
		if ((*a)->in_lic == 0)
		{
			pb(a, b, 1);
			if ((*b)->pos_number < size / 2)
				rb(b, 1); 
		}
		else if ((*a)->in_lic == 1)
			ra(a, 1);
	}
}
void	big_sorts(t_node **a, t_node **b, int size)
{
	if (size > 3)
	{
		lic(a);
		is_in_lic(a);
		pos_number(a);
		first_sort(a, b, size);
	}
}

void	sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, 1);
	}
	sort3(a, size);	
	big_sorts(a, b, size);
	//sort10(&a, size);
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