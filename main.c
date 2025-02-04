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

int handle_arg(char **arg, s_list **stack)
{
	int i;
	int c;
	char **sp_arg;

	c = 0;
	i = 0;
	while (arg[i])
	{
		sp_arg = ft_split(arg[i], ' ');
		// if ((arg[i] > '9' || arg[i] < '0') && arg[i] != ' ' && arg[i] != '-')
		// 	return 0;
		i++;
	c = 0;
	while (sp_arg[c])
	{
		new_node(stack, ft_atoi(sp_arg[c]));
		c++;
	}
	}
	return 1;
}

int main(int argc, char **argv)
{
	int a = 1;
	s_list *stacka = NULL;
	if (argc == 1)
		return ft_error();
	if(handle_arg(argv + 1, &stacka) == 0)
		return ft_error();
	s_list *currenta = stacka;
	printf("<stackA>\n");
    while (currenta)
    {
		
        printf("[%d]\n", currenta->data);
        currenta = currenta->next;
    }
}
