#include "morse.h"

int	main(void)
{
	char	*cypher_text[] = {"0010 01 11 111 001 000", "11 01 10", "1 0000 01 1", "1010 111 11 0 000", "011 00 1 0000", "1 0000 0", "01 0100 1 0 010 10 01 1 0", "0001 0 010 000 00 111 10", "111 0010", "001100", "001100", "001100", NULL};

	char	*code[] = {"01", "1000", "1010", "100", "0", "0010", "110", "0000", "00", "0111", "101", "0100", "11", "10", "111", "0110", "1101", "010", "000", "1", "001", "0001", "011", "1001", "1011", "1100", "11111", "01111", "00111", "00011", "00001", "00000", "10000", "11000", "11100", "11110", "001100", "101011", "010101", "110011", "101010", "111000", "01010", "100001", "10010", "10001", NULL};
	char	alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n', 'o' ,'p' , 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '?', '!', '.', ';', ':', '+', '-', '/', '=' };
	char	**characters;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (cypher_text[i])
	{
		j = 0;
		characters = ft_split(cypher_text[i], ' ');
		if (characters == NULL)
		{
			free_all(characters);
			return (0);
		}
		while (characters[j])
		{
			k = 0;
			while (code[k])
			{
				if (strcmp(code[k], characters[j]) == 0)
				{
					printf("%c", alpha[k]);
					break ;
				}
				k++;
			}
			j++;
		}
		printf(" ");
		free_all(characters);
		i++;
	}
	printf("\n");
}

char	**ft_split(char *string, char sep)
{
	int		words;
	char	**split_string;
	int		i;
	int		j;

	words = count_words(string, sep);
	split_string = calloc(words + 1, sizeof(char *));
	if (split_string == NULL)
		return (0);
	i = 0;
	j = 0;
	while (string[i])
	{
		split_string[j] = get_word(string, sep, &i);
		if (split_string[j] == NULL)
			return (free_all(split_string));
		j++;
	}
	split_string[words] == NULL;
	return (split_string);
}

char	*get_word(char *string, char sep, int *i)
{
	char	*word;
	int		j;

	while (string[*i] == sep)
		(*i)++;
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
	while (string[i])
	{
		while (string[i] == sep)
			i++;
		words++;
		while (string[i] != sep && string[i])
			i++;
	}
	return (words);
}

char	**free_all(char	**split_string)
{
	int	i;

	i = 0;
	while (split_string[i])
	{
		free(split_string[i]);
		split_string[i] == NULL;
		i++;
	}
	free(split_string);
	return (NULL);
}