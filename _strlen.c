/**
 * _strlen - gets the length of a string
 * @str: string to examine
 *
 * Return: returns the length of the string
 */

int _strlen(char *str)
{
	int i, size = 0;

	for (i = 0; str[i] != '\0'; ++i)
	{
		++size;
	}

	return (size);
}
