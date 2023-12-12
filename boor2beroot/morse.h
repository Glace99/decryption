#ifndef MORSE_H
# define MORSE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	**ft_split(char *string, char sep);
int		count_words(char *string, char sep);
char	*get_word(char *string, char sep, int *i);
void	free_split(char	**split);

#endif