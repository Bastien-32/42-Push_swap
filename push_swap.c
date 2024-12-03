#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i]) 
	{
		if (str[i]<= '0' || str[i] >= '9')
			return (0);
		i++;
	}
	if (str[i - 1] == '-')
		return (0);
	return (1);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
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


int	main( int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*temp;

	i = 1;
	if (argc <= 1)
	{
		write(1, "not enough arguments are given", 29);
		return (1);
	}
	while (argv[i])
	{
		if (!is_number(argv[i]))
		{
			write(1, "All arguments must be numbers", 30);
			return (1);
		}
		i++;
	}
	stack_a = ft_lstnew(argv[1]);
	i = 2;
	while (argv[i])
	{
		temp = ft_lstnew(argv[i]);
		ft_lstadd_back(&stack_a, temp);
		i++;
	}
	i = 1;
	while (stack_a)
	{
		printf("%s\n", (char *)stack_a->content);
		stack_a = stack_a->next;
	}
	printf("-   -\n");
	printf("a   b\n");
	return (0);
}

//test is_number
#include <stdio.h>

/*int main (void)
{
	int i;
	char *str = "-1";

	i = is_number(str);
	printf("%d", i);
	return (0);
}*/

/*
verifications des elements passes en parametres :
	- comprend au moins 3 arguments
	- s'assurer que c'est un nombre
	- verifier que ce n'est pas deja trie

fonction push_swap
	- mettre tous les nombres dans une liste chainee a
	- creer une liste chainee b pour deplacer les nombres 
	- creer les fonctions de tri (ra, rb,...)
	- trouver le nombre median 2 pistes : 
		- soit le nombre du milieu de la liste 
		- soit la valeur du nombre median par exemple pour 3 -10000  5 10 1, 3 est le nombre median

algo turc

exo exam : vfuster git exos
*/