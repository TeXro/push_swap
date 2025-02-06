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
	int		*result;
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

size_t ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int repeat(char **arg)
{
	int i;
	int c;
	int st;
	i = 0;
	while (arg[i])
	{
		c = 0;
		if (ft_strchr(arg[i], ' '))
		{
			printf("-->space=:%s:\n", arg[i]);
			while (arg[i][c])
			{
				printf("{");
				if (arg[i][c] == ' ')
				{	
					// "123X77X88"
					// 	0123
					//  
					st =+ c;
					printf("(st=%d)(c=%d)\n", st, c);
					// while (condition)
					// {
					// 	printf("%c", arg[i][c - st]);
					// 	c++;
					// }
					
				}
				
				printf("}");
				c++;
			}
			
		}
		c = i + 1;
		while (arg[c])
		{
			// ./push_swap 34 5 6 "2 5" 754
			if (ft_atoi(arg[i]) == ft_atoi(arg[c]))
				return 1;
			c++;
		}
		i++;
	}
	return 0;
}
int is_valid(char **arg)
{
	int	i;
	int	c;

	i = 0;
	while (arg[i])
	{
		c = 0;
		while (arg[i][c])
		{
			if (arg[i][c + 1] == '+' || arg[i][c + 1] == '-') 
				return 1;
			if ((arg[i][c] != '+') && (arg[i][c] != '-')){
				if((arg[i][c] < '0' || arg[i][c] > '9') && (arg[i][c] != ' '))
					return 1;
			}
			c++;
		}
		i++;
	}
	return 0;
}

int check_arg(char **arg)
{	
	if (is_valid(arg) == 1)
		return 1;
	if (repeat(arg) == 1)
		return 1;
	return 0;
}

int handle_arg(char **arg, s_list **stack)
{
	int i;
	int a;
	int *sp_arg;

	i = 0;
	while (arg[i])
	{
		sp_arg = ft_int_split(arg[i], ' ');
		a = 0;
		while (sp_arg[a])
		{
			new_node(stack, sp_arg[a]);
			a++;
		}
		// free(sp_arg);
		i++;
	}
	// while (a)
	// {
	// 	free(ar)
	// }
	
	return 0;
}

int main(int argc, char **argv)
{
	int a = 1;
	s_list *stacka = NULL;

	if (check_arg(argv + 1) == 1)
		return ft_error();
	if (argc == 1)
		return ft_error();
	handle_arg(argv + 1, &stacka);

	s_list *currenta = stacka;
	printf("<stackA>\n");
    while (currenta)
    {
        printf("[%d]\n", currenta->data);
        currenta = currenta->next;
    }
}
