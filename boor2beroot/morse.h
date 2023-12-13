#ifndef MORSE_H
# define MORSE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	**ft_split(char *string, char sep);
int		count_words(char *string, char sep);
char	*get_word(char *string, char sep, int *i);
char	**free_all(char	**split_string);

#endif