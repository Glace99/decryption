#include <stdio.h>

void	loop(char *funk, char *message, int *i, int *cell);

int main(void)
{
	char	*funk = "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>.>---.++++++++++++.++.++++++.--.<<++.>>------.------------.+++++++++++++.<<.>>++++++.------------.-------. +++++++++++++++++++.<<.>>----------------.+++++.+++++++++.-------------.--.+ ++++++++++++++++.--------.+++++++++++++.<<.>>-----------------------.+++.+++ ++++.---.----.+++++++++++++++++.-----------------.-.<<.>>+++++.+++++.<<.>-------...";
	char	message[10000] = {0};
	int		temp;
	int		i;
	int		cell;

	i = 0;
	cell = 0;
	while (funk[i] != '\0')
	{
		if (funk[i] == '+')
			message[cell]++;
		else if (funk[i] == '-')
			message[cell]--;
		else if (funk[i] == '<')
			cell--;
		else if (funk[i] == '>')
			cell++;
		else if (funk[i] == '[')
			loop(funk, message, &i, &cell);
		else if (funk[i] == '.')
			printf("%c", message[cell]);
		i++;
	}
}

void	loop(char *funk, char *message, int *i, int *cell)
{
	int	temp;

	loop:
	if (message[*cell] == 0)
	{
		while (funk[*i] != ']')
			(*i)++;
		return ;
	}
	temp = *i;
	while (funk[*i] != ']')
	{
		if (funk[*i] == '+')
			message[*cell]++;
		else if (funk[*i] == '-')
			message[*cell]--;
		else if (funk[*i] == '>')
			(*cell)++;
		else if (funk[*i] == '<')
			(*cell)--;
		(*i)++;
	}
	if (message[*cell] != 0)
	{
		*i = temp;
		goto loop;
	}
	return ;
}
