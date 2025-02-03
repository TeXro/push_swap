#include "push_swap.h"

typedef struct s_list
{
    int data;
    struct s_list *next;
}s_list;

void new_node(s_list **stack, int num)
{
	s_list*tmp;

	s_list *node = (s_list *)malloc(sizeof(s_list));
	if (!node)
		return ;
	node->data = num;
	node->next = NULL;
		if (*stack == NULL)
		{
			*stack = node;
			return ;
		}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

int handle_arg(char *arg, s_list **stack)
{
	int i;
	char **sp_arg;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] > '9' || arg[i] < '0') && arg[i] != ' ' && arg[i] != '-')
			return 0;
		i++;
	}
	sp_arg = ft_split(arg, ' ');
	i = 0;
	while (sp_arg[i])
	{
		new_node(stack, ft_atoi(sp_arg[i]));
		i++;
	}
	return 1;
}

int main(int argc, char **argv)
{
	int a = 1;
	s_list *stacka = NULL;
	if (argc == 1)
		return ft_error();
	int c = 0;
	printf("<sp_arg>\n");
	while (argv[a])
	{
		if(handle_arg(argv[a], &stacka) == 0)
			return ft_error();
		a++;
	}
	s_list *currenta = stacka;
	s_list *currents = stacka;
	printf("<stackA>\n");
    while (currenta)
    {
		
        printf("[%d]\n", currenta->data);
        currenta = currenta->next;
		if (currenta && (stacka->data == currenta->data))
		{
			printf("match\n%d = %d", stacka->data, currenta->data);
		}
    }
}
