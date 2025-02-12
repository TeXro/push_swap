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

static int	count_int(const char *s, char c)
{
	int		count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{  
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	intlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

// static void	*free_int(int *arr, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (NULL);
// }

static int	allocint(const char *s, int len)
{
	int	word;
	int		i;

	word = 0;
	i = 0;
	while (i < len)
	{
		word = word * 10 + (s[i] - '0');
		i++;
	}
	return (word);
}

int	*ft_int_split(char const *s, char c)
{
	int	*result;
	int		i;
	int		word_count;

	if (!s)
		return (NULL);
	i = 0;
	
	word_count = count_int(s, c);
	result = malloc(sizeof(int) * (word_count));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = allocint(s, intlen(s, c));
		// if (!result[i])
		// 	return (free_int(result, i));
		s += intlen(s, c);
		i++;
	}
	// result[i] = NULL;
	return (result);
}


int handle_arg(char *arg, s_list **stack)
{
	int i;

	i = 0;
		while (arg[i])
	{
		if ((arg[i] > '9' || arg[i] < '0') && arg[i] != ' ' && arg[i] != '-')
			return 0;
		i++;
	}
	int *sp_arg = ft_int_split(arg, ' ');
	i = 0;
	while (sp_arg[i])
	{
		new_node(stack, sp_arg[i]);
		i++;
	}
	return 1;
}

int main()
{
	
	int argc = 4;
	char **argv = malloc(30);

	argv[1] = malloc(4);
	argv[1] = "70";
	argv[2] = malloc(4);
	argv[2] = "28";
	argv[3] = malloc(4);
	argv[3] = "34";
	int a = 1;
	s_list *stacka = NULL;
	if (argc == 1)
		return ft_error();
	int c = 0;
	while (argv[a])
	{
		if(handle_arg(argv[a], &stacka) == 0)
			return ft_error();
		a++;
	}

	s_list *currenta = stacka;
	printf("<stackA>\n");
    while (currenta)
    {
        printf("[%d]\n", currenta->data);
        currenta = currenta->next;
    }
}
