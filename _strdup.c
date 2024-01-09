#include <stddef.h>
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: returns pointer to the string and NULL if any error
 * occur
 */
char *_strdup(const char *str)
{
	char *string;
	int size = 0, i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; ++i)
	{
		++size;
	}

	string = malloc(sizeof(char) * (size + 1));
	if (string == NULL)
		return (NULL);

	for (j = 0; str[j] != '\0'; ++j)
	{
		string[j] = str[j];
	}

	string[j] = '\0';

	return (string);
}
