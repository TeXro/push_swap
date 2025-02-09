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

int repeat(char **argv)
{
	int i = 0;
	int p = 0;
	int c = 0;
	int b = 0;
	int z = 0;

	while (argv[i])
	{
		p = i + 1;
		b = 0;
		c = 0;
		//			i      p    
		//         [0]    [1]          [2] [3] [4] [5] [6]
		// 			12     "33  5 12 6 "

		// 		   --b------------c------------
		// 		    012    012 0 0 0
		
		while (argv[p])
		{
			if (argv[i][b] != argv[p][c])
			{
				if (ft_strchr(argv[i], ' ') && argv[i][b])
				{
					while ((argv[i][b]) != ' ' && argv[i][b])
						b++;
					while ((argv[i][b]) == ' ' && argv[i][b])
						b++;
					c = 0;
					continue;
				}
				if (ft_strchr(argv[p] + c, ' '))
				{
					while ((argv[p][c]) != ' ')
						c++;
					while ((argv[p][c]) == ' ')
						c++;
					b = 0;
					continue;
				}
				p++;
				c = 0;
				b = 0;	
				continue;
			}
			if (argv[i][b] == argv[p][c] && (argv[i][b] && argv[p][c]))
			{
				c++;
				b++;
				if (((!argv[i][b] || argv[i][b] == ' ')  && (!argv[p][c] || argv[p][c] == ' ')))
					return 1;
				continue;
			}
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
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	int a = 1;
	s_list *stacka = NULL;

	if (repeat(argv + 1) == 1)
		return ft_error();
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
