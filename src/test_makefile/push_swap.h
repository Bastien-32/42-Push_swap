/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:44:23 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/02 16:32:25 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h> 
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}					t_node;

/* ****************************************************************************
									sorts
**************************************************************************** */

void		sort(t_node **a, t_node **b, int size);
void		sort3(t_node **a, int size);
void		sort5(t_node **a, t_node **b, int size);
//void		sort10(t_node **a, int size);

/* ****************************************************************************
									check_args_and_stack
**************************************************************************** */

int			check_args(int argc, char **argv);
int			is_number(const char *str);
int			check_stack(t_node **a);
int			a_is_sorted(t_node **a);
int			a_contain_doubles(t_node **a);

/* ****************************************************************************
									init_stack
**************************************************************************** */

void		init_stack(int argc, char **argv, t_node **a);
char		**parse_args(int argc, char **argv);

/* ****************************************************************************
									commands
**************************************************************************** */
void		rotate(t_node **stack);
void		ra(t_node **a, int print);
void		rb(t_node **b, int print);
void		rr(t_node **a, t_node **b, int print);

void		*reverse_rotate(t_node **stack);
void		rra(t_node **a, int print);
void		rrb(t_node **b, int print);
void		rrr(t_node **a, t_node **b, int print);

void		swap(t_node **stack);
void		sa(t_node **a, int print);
void		sb(t_node **b, int print);
void		ss(t_node **a, t_node **b, int print);

void		push(t_node **src, t_node **dest);
void		pa(t_node **a, t_node **b, int print);
void		pb(t_node **a, t_node **b, int print);

/* ****************************************************************************
									ft_split_ps
**************************************************************************** */

char		**ft_split(char *str, char separator);
int			nwords(char *str, char reject);
int			lenword(char *str, int i, char separator);
char		*ft_substr(char *str, int start, int len);
//static char	**free_split(char **tab);

/* ****************************************************************************
									lib_utils
**************************************************************************** */

t_node		*ft_lstnew(int content);
void		ft_lstadd_front(t_node **lst, t_node *new);
void		ft_lstadd_back(t_node **lst, t_node *new);
int			ft_atoi(const char *str);
int			lstsize(t_node *lst);

#endif