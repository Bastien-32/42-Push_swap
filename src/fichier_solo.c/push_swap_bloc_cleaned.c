/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bloc_cleaned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:30:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/08 17:37:42 by badal-la         ###   ########.fr       */
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
	int				compt_a;
	int				compt_b;
	int				cheapest;
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
	node->compt_b = 0;
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

	if (!*lst && new)
	{
		*lst = new;
		new->next = *lst;
		new->prev = new;
		return ;
	}
	last = *lst;
	while (last->next && last->next != *lst)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
	new->index = last->index + 1;
}

int	lstsize(t_node *lst)
{
	int		i;
	t_node	*temp_lst;

	if (!lst)
		return (0);
	i = 1;
	temp_lst = lst;
	while (lst->next != temp_lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
	t_node	*swap;

	if (!*stack || !(*stack)->next)
		return;
	swap = (*stack)->next;
	(*stack)->next = swap->next;
	swap->next = *stack;
	*stack = swap;
}
void	sa(t_node **a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}
void	sb(t_node **b, int print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}
void	ss(t_node **a, t_node **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}

void	reverse_rotate(t_node **stack)
{
	if (*stack && (*stack)->prev != *stack)
		*stack = (*stack)->prev;
}
void	rra(t_node **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}
void	rrb(t_node **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}
void	rrr(t_node **a, t_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}

void	rotate(t_node **stack)
{
	if (*stack && (*stack)->next != *stack)
		*stack = (*stack)->next;
}
void	ra(t_node **a, int print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}
void	rb(t_node **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}
void	rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	temp = *src;
	*src = (*src)->next;
	if (*src == temp)
		*src = NULL;
	else
	{
		(*src)->prev = temp->prev;
		temp->prev->next = *src;
	}
	if (!*dest)
	{
		*dest = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *dest;
		temp->prev = (*dest)->prev;
		(*dest)->prev->next = temp;
		(*dest)->prev = temp;
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
	while (str[i])
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
	char	**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (NULL);
		return (split_argv);
	}
	return (argv + 1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
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

int	a_is_sorted(t_node **a, int size_a)
{
	t_node	*temp;
	
	temp = *a;
	while (size_a-- >= 0)
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

	if (!*a)
		return (0);
	temp = *a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2 && temp2 != *a)
		{
			if (temp->content == temp2->content)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
		if (temp == *a)
			break ;
	}
	return (0);
}

int	check_stack(t_node **a, int size_a)
{
	if (a_is_sorted(a, size_a))
		exit (-1);
	if (a_contain_doubles(a))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
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

void	lis(t_node **a)
{
	t_node	*temp_i;
	t_node	*temp_j;
	int		temp_lenght;
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

int	find_max_sub_sequence(t_node **a)
{
	t_node	*temp_a;
	int		max_sub_sequence;

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

void	fill_lis(int index, int next_subsequence, t_node *temp_a, int temp)
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
						break ;
					temp_a = temp_a->prev;
				}
				if (temp_a->content < temp)
					temp_a->in_lic = 1;
			}
			break ;
		}
		temp_a = temp_a->prev;
	}
}

void	is_in_lis(t_node **a)
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
	fill_lis(temp_a->index, next_subsequence, temp_a, temp);
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
		if ((*a)->in_lic == 0)
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
			break;
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
			break;
	}
}

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

void	move_ab_neg(t_node **a, t_node **b, int compt_a, int compt_b)
{
	if (compt_a != 0 && compt_b != 0)
	{
		while (compt_a++ < 0 && compt_b++ < 0)
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
		pa(a, b ,1);
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

void	sort_b_to_a(t_node **a, t_node **b, int size_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		cheapest;

	temp_a = *a;
	temp_b = *b;
	cheapest = search_cheapest(&temp_b);
	if (temp_b->cheapest != cheapest)
	{
		while (temp_b->cheapest != cheapest)
			temp_b = temp_b->next;
	}
	move_number(a, b, temp_b->compt_a, temp_b->compt_b);
	size_b = lstsize(*b);
}

void	second_sort(t_node **a, t_node **b, int size)
{
	int		size_a;
	int		size_b;
	t_node	*temp_b;
	
	temp_b = *b;
	while(lstsize(*b) > 0)
	{
		size_a = lstsize(*a);
		size_b = lstsize(*b);
		actualize_index(a);
		actualize_index(b);
		fill_num_moves_b(*b, size_b);
		fill_num_moves_a(*a, *b, size_a);
		sort_b_to_a(a, b, size_b);
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
		if (pos_number_in_a < lstsize(*a) / 2)
		{
			while (pos_number_in_a-- > 0)
				ra (a, 1);
		}
		else if (pos_number_in_a >= lstsize(*a) / 2)
		{
			while (pos_number_in_a++ < 0)
				rra (a, 1);
		}
	}
}

void	big_sorts(t_node **a, t_node **b, int size)
{
	t_node	*temp_a;
	int	pos_first_number;
	
	if (size > 3)
	{
		lis(a);
		is_in_lis(a);
		pos_number(a);
		first_sort(a, b, size);
		//printf("First sort finish\n");
		second_sort(a, b, size);
		move_first_num_on_top(a);
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
	int 	size_a;
	
	a = NULL;
	b = NULL;
	if (!check_args(argc, argv))
	{
		init_stack(argc, argv, &a);
		size_a = lstsize(a);
		check_stack(&a, size_a);
		sort(&a, &b, size_a);
		
		printlist(&a);
	}
	else
		write(1, "Error\n", 6);
}
