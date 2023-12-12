#include "morse.h"

char	**ft_split(char *string, char sep)
{
	int		words;
	int		i;
	int		j;
	char	**split;

	words = count_words(string, sep);
	split = calloc(words, sizeof(split));
	if (split == NULL)
		return (0);
	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i] == sep)
			i++;
		if (string[i])
		{
			split[j] = get_word(string, sep, &i);
			if (*split == NULL)
			{
				free_split(split);
				return (0);
			}
		}
		j++;
	}
	return (split);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	return ;
}

char	*get_word(char *string, char sep, int *i)
{
	int		j;
	char	*word;

	j = *i;
	while (string[j] && string[j] != sep)
		j++;
	word = calloc(j + 1, sizeof(char));
	if (word == NULL)
		return (0);
	j = 0;
	while (string[*i] && string[*i] != sep)
	{
		word[j] = string[*i];
		j++;
		(*i)++;
	}
	return (word);
}

int	count_words(char *string, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (string[i] == sep)
		i++;
	if (string[i])
		words++;
	while (string[i])
	{
		if (string[i] == sep)
		{
			while (string[i] == sep)
				i++;
			if (string[i])
				words++;
			continue ;
		}
		i++;
	}
	return (words);
}
