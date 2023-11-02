#include "shell.h"


/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **splitstring(char *string, const char *delim)
{
	int x, won;
	char **array;
	char *token;
	char *copy;

	copy = malloc(string_len(string) + 1);
	if (copy == NULL)
	{
		perror(get_env("_"));
		return (NULL);
	}
	x = 0;
	while (string[x])
	{
		copy[x] = string[x];
		x++;
	}
	copy[x] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);
	
	x = 1;
	won = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = real_alloc(array, (sizeof(char *) * (won - 1)), (sizeof(char *) * won));
		array[x] = _strdup(token);
		x++;
		won++;
	}
	free(copy);
	return (array);
}

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void execute(char **argv)
{

	int x;
	int stat;

	if (!argv || !argv[0])
		return;
	x = fork();
	if (x == -1)
	{
		perror(get_env("_"));
	}
	if (x == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&stat);
}

/**
 * real_alloc- Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 *
 * Return: New resized Pointer
 */

void *real_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int x;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (x = 0; x < old_size; x++)
			new[x] = old[x];
		free(ptr);
		for (x = old_size; x < new_size; x++)
			new[x] = '\0';
	}
	if (new_size < old_size)
	{
		for (x = 0; x < new_size; x++)
			new[x] = old[x];
		free(ptr);
	}
	return (new);
}

/**
 * free_arv- frees pointers arv
 *@arv: array of pointers
 */

void free_arv(char **arv)
{
	int x;

	for (x = 0; arv[x]; x++)
		free(arv[x]);
	free(arv);
}
