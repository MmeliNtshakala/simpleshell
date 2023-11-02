#include "shell.h"

/**
 * _strdup- returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 *
 * Return: pointer to a string
 */
char *_strdup(char *string)
{
	int x;
	int num;
	char *next;

	if (!string)
	{
		return (NULL);
	}
	for (num = 0; string[num] != '\0';)
	{
		num++;
	}
	next = malloc(sizeof(char) * num + 1);
	if (!next)
	{
		return (NULL);
	}
	for (x = 0; x < num; x++)
	{
		next[x] = string[x];
	}
	next[num] = string[num];
	return (next);
}

/**
 * concat_all- concats 3 strings in a newly allocated memory
 * @name: string
 * @sep: 2nd string
 * @value: 3rd string
 *
 * Return: pointer to the new string
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *output;
	int l1, l2, l3, x, num;

	l1 = string_len(name);
	l2 = string_len(sep);
	l3 = string_len(value);

	output = malloc(l1 + l2 + l3 + 1);
	if (!output)
		return (NULL);

	for (x = 0; name[x]; x++)
		output[x] = name[x];
	num = x;

	for (x = 0; sep[x]; x++)
		output[num + x] = sep[x];
	num = num + x;

	for (x = 0; value[x]; x++)
		output[num + x] = value[x];
	num = num + x;

	output[num] = '\0';

	return (output);
}

/**
 * string_len- string length
 * @s: pointer to the string
 *
 * Return: the length of string
 */
int string_len(char *s)
{
	int x = 0;

	while (*(s + x) != '\0')
	{
		x++;
	}
	return (x);
}

/**
 * _putchar- writes the character c to stdout
 * @charecter: The character to print
 *
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char charecter)
{
	return (write(1, &charecter, 1));
}

/**
 * _puts- prints a string
 * @string: pointer to string
 */

void _puts(char *string)
{
	int x = 0;

	while (string[x])
	{
		_putchar(string[x]);
		x++;
	}
}
