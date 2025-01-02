#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>
#include <limits.h>

typedef struct s_node
{
	int				content;
	int 			lenght;
	int 			sub_sequence;
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
	node->next = NULL;
	return (node);
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

void	init_stack(int argc, char **argv, t_node **a)
{
	int		i;
	char	**split_argv;
	
	if (argc == 2)
		split_argv = parse_args(argc, argv);
	else
		split_argv = argv + 1;
	*a = ft_lstnew(ft_atoi(split_argv[0]));
	i = 1;
	while (split_argv[i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(split_argv[i++])));
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

void	printlist(t_node *temp_a)
{
	printf("a  l  s\n");
	printf("-  -  -\n");
	while (temp_a)
	{
		if (temp_a->content < 10)
			printf(" %d  %d  %d\n", temp_a->content, temp_a->lenght, temp_a->sub_sequence);
		else
			printf("%d  %d  %d\n", temp_a->content, temp_a->lenght, temp_a->sub_sequence);
		temp_a = temp_a->next;
	}
}
t_node *lic(t_node **a)
{
	t_node	*temp_i;
	t_node	*temp_j;
	int temp_lenght;
	int temp_sub_sequence;
	int i;

	temp_i = (*a)->next;
	while (temp_i)
	{
		temp_j = *a;
		i = 0;
		while (temp_j < temp_i)
		{
			if (temp_j->content < temp_i->content)
			{
				temp_lenght = temp_j->lenght + 1;
				if(temp_lenght > temp_i->lenght)
				{
					temp_i->lenght = temp_lenght;
					temp_sub_sequence = i;
					if(temp_sub_sequence > temp_i->sub_sequence)
						temp_i->sub_sequence = temp_sub_sequence;
				}
			}
			temp_j = temp_j->next;
			i++;
		}
		printf("cont temp_i =%d | cont temp_j =%d | temp_i->lenght =%d | temp_i->sub_sequence=%d\n", temp_i->content, temp_j->content, temp_i->lenght, temp_i->sub_sequence);
		temp_i = temp_i->next;
	}
	return(temp_i);
}
int main(int argc, char *argv[])
{
	//char *a ="00 04 12 02 10 06 09 13 03 11 07 15";
	t_node 	*a;
	t_node 	*b;
	int 	size;
	
	a = NULL;
	b = NULL;
	init_stack(argc, argv, &a);
	size = lstsize(a);

	a = lic(&a);
	t_node	*temp_a;
	t_node	*temp_b;
	printf("Listes après tri : \n");
	temp_a = a;
	temp_b = b;
	printlist(temp_a);
}