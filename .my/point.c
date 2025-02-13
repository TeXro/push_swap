#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	count_num(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == ' ')
			in_word = 0;
		s++;
	}
	return (count);
}

int	intlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	return (len);
}

int	charint(const char *s, int len)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (i < len)
	{
		word = word * 10 + (s[i] - '0');
		i++;
	}
	return (word);
}

int	*ft_int_split(char const *s)
{
	int	*result;
	int	i;
	int	numbers;

	if (!s)
		return (NULL);
	i = 0;
	numbers = count_num(s);
	result = malloc(sizeof(int) * (numbers));
	if (!result)
		return (NULL);
	i = 0;
	while (i < numbers)
	{
		while (*s == ' ')
			s++;
		result[i] = charint(s, intlen(s));
		s += intlen(s);
		i++;
	}
	return (result);
}


int main()
{
	int *res;
	res = ft_int_split("1 2 0");
	printf("%d", res[1]);
	printf("%p", res[1]);
	
	
}