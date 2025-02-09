#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
	{
		length++;
	}
	return (length);
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


int main(int argc, char **argv)
{
	argv += 1;
	int i = 0;
	int p = 0;;
	int c = 0;
	int b = 0;

	while (argv[i])
	{
		//			    i   p    
		//         [0] [1] [2] [3] [4] [5] [6]
		// ./a.out 111 2   45  11  3   5   2 
		// 		   --b-----------c--------------
		// 		   012 0   01  013 0   0   0
		int c = 0;
		int b = 0;
		// if (ft_strchr(argv[i] + b, ' '))
		// {
		// 	while (argv[i][c])
		// 	{
		// 		if (argv[i][c] != argv[i][b])
		// 		{
		// 			while ((argv[i][b]) != ' ')
		// 				b++;
		// 			while ((argv[i][b]) == ' ')
		// 				b++;
		// 		}
		// 		if (((!argv[i][b] || argv[i][b] == ' ')  && (!argv[i][c] || argv[i][c] == ' ')))
		// 		{
		// 			printf("match,\n");
		// 			return 1;
		// 		}
		// 	}
		// 	i++;
		// }
		p = i + 1;
		b = 0;
		c = 0;
		while (argv[p])
		{
			if (argv[i][b] != argv[p][c])
			{
				printf("no,\n");
				if (ft_strchr(argv[p] + c, ' '))
				{
					printf("?%s?", ft_strchr(argv[p], ' '));
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
				printf("p,\n");
				c++;
				b++;
				if (((!argv[i][b] || argv[i][b] == ' ')  && (!argv[p][c] || argv[p][c] == ' ')))
				{
					printf("match,\n");
					return 1;
				}
				continue;
			}
		}
		i++;
	}
	return 0;
	
}