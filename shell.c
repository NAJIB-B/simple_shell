#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * free_args - free arguments array
 *
 */

void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; ++i)
	{
		free(args[i]);
	}
	free(args);
}

/**
 * main - Simple shell program entry point
 * @argc: number of args passed to main
 * @argv: array of args passed to main
 *
 * Return: returns 0 on success and 1 otherwise
 */

int main(int argc, char **argv, char **envc)
{
	int i;
	char **args, *path, *path_to_check;
	pid_t child_process;

	(void)argc;

	while (1)
	{
		printf("#cisfun$ ");

		args = get_user_input();
		path_to_check = _strdup(args[0]);
		path = find_path(path_to_check, envc);

		if (path == NULL)
		{
			free_args(args);
			continue;
		}
		args[0] = _strdup(path);
		free(path);

		child_process = fork();
		if (child_process == -1)
		{
			perror("fork");
			return (1);
		}
		if (child_process == 0)
		{
			execve(args[0], args, envc);
			perror(argv[0]);
		}
		else
		{
			wait(&i);
		}
		free_args(args);
	}
}
