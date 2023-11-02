#include "shell.h"

/**
* c_build- checks if buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*c_build(char **arv))(char **arv)
{
	int x;
	int num;
	mybuild T[] = {
		{"exit", escaping},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (x = 0; T[x].name; x++)
	{
		num = 0;
		if (T[x].name[num] == arv[0][num])
		{
			for (num = 0; arv[0][num]; num++)
			{
				if (T[x].name[num] != arv[0][num])
					break;
			}
			if (!arv[0][num])
				return (T[x].func);
		}
	}
	return (0);
}
