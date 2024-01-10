#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * get_last_part - gets the last part of a path
 * @str: the path to examine
 *
 * Return: returns the last part of the path
 */

char *get_last_part(char *str)
{
	char *last_arg = NULL, *token;

	token = strtok(str, "/_");

	while (token != NULL)
	{
		if (last_arg != NULL)
			free(last_arg);
		last_arg = _strdup(token);
		token = strtok(NULL, "/_");
	}

	free(str);

	return (last_arg);
}

/**
 * find_path - checks for the path of a command
 * @command: the command to check for
 * @envc: array of the enviroment variables
 * @argv_zero: the name of the running program
 *
 * Return: returns the path to the command
 */

char *find_path(char *command, char **envc, char *argv_zero)
{
	char *path, *token, *arg, *valid_path;

	arg = get_last_part(command);

	path = _getenv("PATH", envc);

	token = strtok(path, ":");

	while (token != NULL)
	{
		valid_path = string_joiner(token, arg);

		if (access(valid_path, F_OK | X_OK) == -1)
		{
			free(valid_path);
			token = strtok(NULL, ":");
			continue;
		}
		else
		{
			free(arg);
			free(path);
			return (valid_path);
		}
	}

	perror(argv_zero);
	free(arg);
	free(path);
	return (NULL);
}

/**
 * string_joiner - joins two strings together
 * @str1: first string
 * @str2: second string
 *
 * Return: returns the new string
 */

char *string_joiner(char *str1, char *str2)
{
	int size = 0, i, j;

	char *new_string;

	if (str1 == NULL || str2 == NULL)
		return (NULL);

	size += _strlen(str1);
	size += _strlen(str2);

	new_string = malloc(sizeof(char) * (size + 2));

	for (i = 0; str1[i] != '\0'; ++i)
	{
		new_string[i] = str1[i];
	}

	new_string[i] = '/';
	++i;

	for (j = 0; str2[j] != '\0'; ++j)
	{
		new_string[i] = str2[j];
		++i;
	}
	new_string[i] = '\0';

	return (new_string);
}
