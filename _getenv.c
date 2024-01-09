#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * _getenv - get the value of an enviromental variable
 * @name: name of variable to look for
 * @envc: array of enviromental variables
 *
 * Return: returns the value of the env variable or NULL if is not found
 */

char *_getenv(const char *name, char **envc)
{
	int i, cmp_val;
	char *env, *env_result;
	char *environ_copy;
	char *arg = _strdup(name);

	for (i = 0; envc[i] != NULL; ++i)
	{
		environ_copy = _strdup(envc[i]);
		env = strtok(environ_copy, "=");

		cmp_val = strcmp(env, arg);

		if (cmp_val == 0)
		{
			env = strtok(NULL, "");
			env_result = _strdup(env);
			free(arg);
			free(environ_copy);
			return (env_result);
		}
		else
		{
			free(env);
			continue;
		}
	}
	free(arg);
	return (NULL);
}
