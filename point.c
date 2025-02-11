#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	count_int(const char *s, char c)
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

int	intlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

int	allocint(const char *s, int len)
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

int *ft_int_split(char const *s, char c)
{
	int		result[count_int(s, c)];
	int		i;
	int		word_count;
	int		*rtn;

	if (!s)
		return (NULL);
	word_count = count_int(s, c);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = allocint(s, intlen(s, c));
		s += intlen(s, c);
		i++;
	}
	rtn = result;
	return(rtn);
}

int main()
{
	int *res;
	res = ft_int_split("1 2", ' ');
	
	
}