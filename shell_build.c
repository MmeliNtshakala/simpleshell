#include "shell.h"

/**
 * escaping- exits the shell
 * @arv: array of words
 */
void escaping(char **arv)
{
	int x;
	int num;

	if (arv[1])
	{
		num = _atoi(arv[1]);
		if (num <= -1)
			num = 2;
		free_arv(arv);
		exit(num);
	}
	for (x = 0; arv[x]; x++)
		free(arv[x]);
	free(arv);
	exit(0);
}

/**
 * _atoi- converts a string to integer
 *@s: pointer to string
 *Return: the integer
 */
int _atoi(char *s)
{
	int x;
	int y, sgn = 1;

	x = 0;
	y = 0;
	while (!((s[x] >= '0') && (s[x] <= '9')) && (s[x] != '\0'))
	{
		if (s[x] == '-')
		{
			sgn = sgn * (-1);
		}
		x++;
	}
	while ((s[x] >= '0') && (s[x] <= '9'))
	{
		y = (y * 10) + (sgn * (s[x] - '0'));
		x++;
	}
	return (y);
}

/**
 * env- prints environment
 * @arv: array  arguments
 */
void env(char **arv __attribute__ ((unused)))
{
	int x;

	for (x = 0; environ[x]; x++)
	{
		puts(environ[x]);
		puts("\n");
	}

}

/**
 * _setenv - Initialize new enviro variable and modify a new one
 * @arv: array of words
 */
void _setenv(char **arv)
{
	int x;
	int num, integers;

	if (!arv[1] || !arv[2])
	{
		perror(get_env("_"));
		return;
	}

	for (x = 0; environ[x]; x++)
	{
		num = 0;
		if (arv[1][num] == environ[x][num])
		{
			while (arv[1][num])
			{
				if (arv[1][num] != environ[x][num])
					break;

				num++;
			}
			if (arv[1][num] == '\0')
			{
				integers = 0;
				while (arv[2][integers])
				{
					environ[x][num + 1 + integers] = arv[2][integers];
					integers++;
				}
				environ[x][num + 1 + integers] = '\0';
				return;
			}
		}
	}
	if (!environ[x])
	{

		environ[x] = concat_all(arv[1], "=", arv[2]);
		environ[x + 1] = '\0';

	}
}

/**
 * _unsetenv- Remove enviro variable
 * @arv: array of words
 */
void _unsetenv(char **arv)
{
	int x, num;

	if (!arv[1])
	{
		perror(get_env("_"));
		return;
	}
	for (x = 0; environ[x]; x++)
	{
		num = 0;
		if (arv[1][num] == environ[x][num])
		{
			while (arv[1][num])
			{
				if (arv[1][num] != environ[x][num])
					break;

				num++;
			}
			if (arv[1][num] == '\0')
			{
				free(environ[num]);
				environ[x] = environ[x + 1];
				while (environ[x])
				{
					environ[x] = environ[x + 1];
					x++;
				}
				return;
			}
		}
	}
}
