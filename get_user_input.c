#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenizer - tokenize string and place in a NUll terminated array
 * @str: pointer to the string
 *
 * Return: returns the NULL terminated array of strings
 */

char **tokenizer(char *str)
{
	char **result, *token, *dup_input;
	int array_size = 0, i = 0;

	dup_input = _strdup(str);
	token = strtok(dup_input, " ");

	while (token != NULL)
	{
		array_size++;

		token = strtok(NULL, " ");
	}
	free(dup_input);

	result = malloc(sizeof(char *) * (array_size + 1));

	if (result == NULL)
	{
		printf("couldn't allocate memory");
		free(str);
		return (NULL);
	}

	token = strtok(str, " \t");
	if (token == NULL)
	{
		free(result);
		free(str);
		return (NULL);
	}
	while (token != NULL)
	{
		result[i] = _strdup(token);
		i++;
		token = strtok(NULL, " ");
	}
	result[i] = NULL;

	free(str);
	return (result);
}

/**
 * get_user_input - gets user input and puts it in a NULL terminated array
 *
 * Return: returns the NULL terminated array
 */

char **get_user_input()
{
	char *lineptr, **result;
	size_t n = 0;
	ssize_t bytes_read;
	int cmp_val;
	char exit_str[] = "exit";

	lineptr = NULL;

	bytes_read = getline(&lineptr, &n, stdin);

	if (bytes_read == -1)
	{
		free(lineptr);
		exit(0);
	}
	if (lineptr[bytes_read - 1] == '\n')
		lineptr[bytes_read - 1] = '\0';

	cmp_val = _strcmp(exit_str, lineptr);

	if (cmp_val == 0)
	{
		free(lineptr);
		exit(0);
	}
	result = tokenizer(lineptr);

	if (result == NULL)
		return (NULL);

	return (result);
}
